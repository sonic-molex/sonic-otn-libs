#include "sai_adapter.h"

std::vector<sai_object_id_t> *sai_adapter::switch_list_ptr;
switch_metadata *sai_adapter::switch_metadata_ptr;


sai_adapter::sai_adapter()
{
    // ptr
    switch_list_ptr = &obj_list;
    switch_metadata_ptr = &metadata;

    // api set
    switch_api.create_switch = &sai_adapter::create_switch;
    switch_api.remove_switch = &sai_adapter::remove_switch;
    switch_api.get_switch_attribute = &sai_adapter::get_switch_attribute;
    switch_api.set_switch_attribute = &sai_adapter::set_switch_attribute;

    router_interface_api.create_router_interface = &sai_adapter::create_router_interface;
    router_interface_api.remove_router_interface = &sai_adapter::remove_router_interface;
    router_interface_api.set_router_interface_attribute = &sai_adapter::set_router_interface_attribute;
    router_interface_api.get_router_interface_attribute = &sai_adapter::get_router_interface_attribute;

    otn_attenuator_api.create_otn_attenuator = &sai_adapter::create_otn_attenuator;
    otn_attenuator_api.remove_otn_attenuator = &sai_adapter::remove_otn_attenuator;
    otn_attenuator_api.set_otn_attenuator_attribute = &sai_adapter::set_otn_attenuator_attribute;
    otn_attenuator_api.get_otn_attenuator_attribute = &sai_adapter::get_otn_attenuator_attribute;

    otn_oa_api.create_otn_oa = &sai_adapter::create_otn_oa;
    otn_oa_api.remove_otn_oa = &sai_adapter::remove_otn_oa;
    otn_oa_api.set_otn_oa_attribute = &sai_adapter::set_otn_oa_attribute;
    otn_oa_api.get_otn_oa_attribute = &sai_adapter::get_otn_oa_attribute;

    otn_ocm_api.create_otn_ocm = &sai_adapter::create_otn_ocm;
    otn_ocm_api.remove_otn_ocm = &sai_adapter::remove_otn_ocm;
    otn_ocm_api.set_otn_ocm_attribute = &sai_adapter::set_otn_ocm_attribute;
    otn_ocm_api.get_otn_ocm_attribute = &sai_adapter::get_otn_ocm_attribute;
    otn_ocm_api.create_otn_ocm_channel = &sai_adapter::create_otn_ocm_channel;
    otn_ocm_api.remove_otn_ocm_channel = &sai_adapter::remove_otn_ocm_channel;
    otn_ocm_api.set_otn_ocm_channel_attribute = &sai_adapter::set_otn_ocm_channel_attribute;
    otn_ocm_api.get_otn_ocm_channel_attribute = &sai_adapter::get_otn_ocm_channel_attribute;

    otn_osc_api.create_otn_osc = &sai_adapter::create_otn_osc;
    otn_osc_api.remove_otn_osc = &sai_adapter::remove_otn_osc;
    otn_osc_api.set_otn_osc_attribute = &sai_adapter::set_otn_osc_attribute;
    otn_osc_api.get_otn_osc_attribute = &sai_adapter::get_otn_osc_attribute;

    // TODO
    //otn_otdr_api.create_otn_otdr = &sai_adapter::create_otn_otdr;
    //otn_otdr_api.remove_otn_otdr = &sai_adapter::remove_otn_otdr;
    //otn_otdr_api.set_otn_otdr_attribute = &sai_adapter::set_otn_otdr_attribute;
    //otn_otdr_api.get_otn_otdr_attribute = &sai_adapter::get_otn_otdr_attribute;

    logger::notice("sai adapter initialized");
}

sai_adapter::~sai_adapter()
{
    logger::notice("sai adapter closed");
}

sai_status_t
sai_adapter::sai_api_query(sai_api_t sai_api_id, void **api_method_table)
{
    switch ((uint32_t)sai_api_id) {
    case SAI_API_SWITCH:
        *api_method_table = &switch_api;
        break;
    case SAI_API_ROUTER_INTERFACE:
        *api_method_table = &router_interface_api;
        break;
    case SAI_API_OTN_ATTENUATOR:
        *api_method_table = &otn_attenuator_api;
        break;
    case SAI_API_OTN_OA:
        *api_method_table = &otn_oa_api;
        break;
    case SAI_API_OTN_OCM:
        *api_method_table = &otn_ocm_api;
        break;
    case SAI_API_OTN_OSC:
        *api_method_table = &otn_osc_api;
        break;
    //case SAI_API_OTN_OTDR:
    //    *api_method_table = &otn_otdr_api;
    //    break;
    default:
        logger::notice("unsupported api request made " + std::to_string(sai_api_id));
        return SAI_STATUS_FAILURE;
    }
    return SAI_STATUS_SUCCESS;
}

sai_object_type_t
sai_adapter::sai_object_type_query(sai_object_id_t sai_object_id) {
    // top level, switch
    if (switch_metadata_ptr->switch_id == sai_object_id) {
        return SAI_OBJECT_TYPE_SWITCH;
    }

    // otn sai
    if (switch_metadata_ptr->sai_id_map.find_object(sai_object_id)) {
        return static_cast<sai_obj *>(switch_metadata_ptr->sai_id_map.get_object(sai_object_id))->sai_object_type;
    }

    // vid
    for (const auto &id : switch_metadata_ptr->vids) {
        if (sai_object_id == id.second) {
            return id.first;
        }
    }

    return SAI_OBJECT_TYPE_NULL;
}
