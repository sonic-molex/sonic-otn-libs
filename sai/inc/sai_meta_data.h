#pragma once

#include <iostream>
#include <list>
#include <map>
#include <saiextensions.h>
#include <vector>
#include <set>
#include <regex>
#include <optional>


#define NULL_HANDLE -1

// object pointer and it's id
class sai_id_map_t
{
public:
    sai_id_map_t()
    {
        // init
        unused_id.clear();
        id_map.clear();
    }

    ~sai_id_map_t()
    {
        free_all();
    }

    void free_id(sai_object_id_t sai_object_id);

    void free_all();

    sai_object_id_t get_new_id(void *obj_ptr)
    {
        sai_object_id_t id;
        if (!unused_id.empty()) {
            id = unused_id.back();
            unused_id.pop_back();
        } else {
            id = id_map.size() + 1;
        }
        id_map[id] = obj_ptr;
        return id;
    }

    void *get_object(sai_object_id_t sai_object_id)
    {
        return id_map[sai_object_id];
    }

    bool find_object(sai_object_id_t sai_object_id)
    {
        return id_map.find(sai_object_id) != id_map.end();
    }

    uint32_t get_ids(std::vector<sai_object_id_t> &ids) {
        for (const auto &it : id_map) {
            ids.push_back(it.first);
        }

        return ids.size();
    }

protected:
    std::map<sai_object_id_t, void *> id_map;
    std::vector<sai_object_id_t> unused_id;
};

class sai_obj
{
public:
    sai_obj(sai_id_map_t &sai_id_map, sai_object_type_t type)
    {
        sai_object_id = sai_id_map.get_new_id(this);
        sai_object_type = type;
    }

    virtual ~sai_obj()
    {
        // free_id(sai_object_id); TODO: fix this
    }

    // variable
    sai_object_id_t sai_object_id;
    sai_object_type_t sai_object_type;
};

class router_interface_obj : public sai_obj
{
public:
    router_interface_obj(sai_id_map_t &sai_id_map) :
        sai_obj(sai_id_map, SAI_OBJECT_TYPE_ROUTER_INTERFACE)
    {
        this->vid = 1;
        this->mac_valid = false;
        this->vid = 0;
        this->type = SAI_ROUTER_INTERFACE_TYPE_VLAN;
    }

    // variable
    sai_mac_t mac;
    bool mac_valid;
    uint16_t vid;
    sai_router_interface_type_t type;
};

class otn_obj : public sai_obj
{
public:
    otn_obj(sai_id_map_t &sai_id_map, sai_object_type_extensions_t type) :
        sai_obj(sai_id_map, (sai_object_type_t)type),
        dev_type(0),
        dev_index(0)
    {
    }

    virtual ~otn_obj() {}

    // variable
    uint32_t dev_type;
    uint32_t dev_index;
    std::string dev_name;
};

class otn_attenuator_obj : public otn_obj
{
public:
    otn_attenuator_obj(sai_id_map_t &sai_id_map) :
        otn_obj(sai_id_map, SAI_OBJECT_TYPE_OTN_ATTENUATOR),
        block_attn(2550),
        set_attn(800),
        attn_mode(SAI_OTN_ATTENUATOR_MODE_CONSTANT_ATTENUATION),
        target_power(0),
        max_power(500),
        max_power_thr(300),
        enable(true)
    {
    }

    // variable
    const uint32_t block_attn;
    uint32_t set_attn;
    uint32_t attn_mode;
    int32_t target_power;
    int32_t max_power;
    int32_t max_power_thr;
    bool enable;
    std::string ingress_port;
    std::string egress_port;
};

class otn_oa_obj : public otn_obj
{
public:
    otn_oa_obj(sai_id_map_t &sai_id_map) :
        otn_obj(sai_id_map, SAI_OBJECT_TYPE_OTN_OA),
        oa_type(SAI_OTN_OA_TYPE_EDFA),
        set_mode(SAI_OTN_OA_AMP_MODE_CONSTANT_GAIN),
        set_gain(2000),
        set_power(800)
    {
    }

    // variable
    int32_t oa_type;
    int32_t set_mode;
    uint32_t set_gain;
    int32_t set_power;
    std::string ingress_port;
    std::string egress_port;
};

class otn_ocm_obj : public otn_obj
{
public:
    otn_ocm_obj(sai_id_map_t &sai_id_map) :
        otn_obj(sai_id_map, SAI_OBJECT_TYPE_OTN_OCM)
    {
    }

    // variable
    std::string monitor_port;
    // lower frequency vs object id
    std::map<sai_uint64_t, sai_object_id_t> channels;
};

class otn_ocm_channel_obj : public otn_obj
{
public:
    otn_ocm_channel_obj(sai_id_map_t &sai_id_map) :
        otn_obj(sai_id_map, SAI_OBJECT_TYPE_OTN_OCM_CHANNEL),
        ocm_id(0),
        lower_frequency(0),
        upper_frequency(0),
        power(0)
    {
    }

    void set_parent(sai_id_map_t &sai_id_map) {
        std::vector<sai_object_id_t> ids;
        sai_id_map.get_ids(ids);

        otn_ocm_obj *parent_obj = NULL;
        for (const auto &it : ids) {
            sai_obj *obj = static_cast<sai_obj *>(sai_id_map.get_object(it));
            if (obj->sai_object_type == (sai_object_type_t)SAI_OBJECT_TYPE_OTN_OCM) {
                otn_ocm_obj *obj_temp = static_cast<otn_ocm_obj *>(obj);
                if (obj_temp->dev_index == this->dev_index) {
                    parent_obj = obj_temp;
                    break;
                }
            }
        }

        if (parent_obj == NULL) {
            // Create ocm first, for future using
            parent_obj = new otn_ocm_obj(sai_id_map);
            parent_obj->dev_index = this->dev_index;
        }

        this->ocm_id = parent_obj->sai_object_id;
        parent_obj->channels[this->lower_frequency] = this->sai_object_id;
    }

    // variable
    sai_object_id_t ocm_id;
    sai_uint64_t lower_frequency;
    sai_uint64_t upper_frequency;
    sai_int32_t power;

    static sai_uint64_t min_frequency;
};

class otn_osc_obj : public otn_obj
{
public:
    otn_osc_obj(sai_id_map_t &sai_id_map) :
        otn_obj(sai_id_map, SAI_OBJECT_TYPE_OTN_OSC),
        freq(198538052)
    {
    }

    // variable
    const uint64_t freq;
};

// TODO
#if 0
class otn_otdr_obj : public otn_obj
{
public:
    otn_otdr_obj(sai_id_map_t &sai_id_map) :
        otn_obj(sai_id_map, SAI_OBJECT_TYPE_OTN_OTDR),
        distance_range(60), pulse_width(3000), reflect_thr(-40.0),
        splice_los_thr(0.5), fiber_end_thr(3.0), sample_res(10.0)
    {
    }

    // variable
    uint32_t distance_range;
    uint32_t pulse_width;
    double reflect_thr;
    double splice_los_thr;
    double fiber_end_thr;
    const double sample_res;

};
#endif

class switch_metadata
{ 
public:
    switch_metadata() : virtual_id(0x0F000000)
    {
        memset(default_switch_mac, 0, 6);

        sai_object_id_t id = virtual_id;
        vids[SAI_OBJECT_TYPE_VIRTUAL_ROUTER] = ++id;
        vids[SAI_OBJECT_TYPE_VLAN] = ++id;
        vids[SAI_OBJECT_TYPE_PORT] = ++id;
        vids[SAI_OBJECT_TYPE_BRIDGE] = ++id;
        vids[SAI_OBJECT_TYPE_HOSTIF_TRAP_GROUP] = ++id;
    }

    // variable
    const uint32_t virtual_id;
    sai_object_id_t switch_id;
    sai_mac_t default_switch_mac;
    sai_id_map_t sai_id_map;

    // id mapping for virtual devices
    std::map<sai_object_type_t, sai_object_id_t> vids;

};
