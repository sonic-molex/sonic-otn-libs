#include "sai_adapter.h"
#include "dev_util.h"
#include "virtual_otn_dev_mgr.h"
// OTN OA

sai_status_t
sai_adapter::create_otn_oa(sai_object_id_t *otn_oa_id,
                            sai_object_id_t switch_id,
                            uint32_t attr_count,
                            const sai_attribute_t *attr_list)
{
    CHECK_SWITCH_ID(switch_id);

    otn_oa_obj *obj = new otn_oa_obj(switch_metadata_ptr->sai_id_map);
    *otn_oa_id = obj->sai_object_id;

    logger::notice(std::string(__func__) + ", object id " + std::to_string(*otn_oa_id));

    // create virtual OA device 
    auto& mgr = virtual_otn_device_manager::instance();
    sai_status_t ret_status = mgr.create_device(obj->sai_object_id,SAI_OBJECT_TYPE_OTN_OA);
    if (ret_status == SAI_STATUS_SUCCESS)
    {
        for (uint32_t i = 0; i < attr_count; i++) {
            sai_status_t tmp_status = set_otn_oa_attribute(obj->sai_object_id, attr_list + i);
            logger::debug(std::string(__func__) + " attr " + std::to_string(attr_list[i].id) + " ret " + std::to_string(tmp_status));
            if (tmp_status != SAI_STATUS_SUCCESS) {
                ret_status = tmp_status;
                break;
            }
        }
    }

    return ret_status;
}

sai_status_t
sai_adapter::remove_otn_oa(sai_object_id_t otn_oa_id)
{
    auto& mgr = virtual_otn_device_manager::instance();
    sai_status_t sai_status_ret = mgr.delete_device(otn_oa_id);
    if (sai_status_ret != SAI_STATUS_SUCCESS)
    {
        logger::warn(std::string(__func__) + ", Did not find Virtual device object id " + std::to_string(otn_oa_id));
    }
    switch_metadata_ptr->sai_id_map.free_id(otn_oa_id);
    return sai_status_ret;
}

sai_status_t
sai_adapter::set_otn_oa_attribute(sai_object_id_t otn_oa_id,
                                   const sai_attribute_t *attr)
{
    logger::notice(std::string(__func__) +
                   ", object id " + std::to_string(otn_oa_id) +
                   ", attr id " + std::to_string(attr->id));

    sai_status_t rc = SAI_STATUS_SUCCESS;
    CAST_OBJ(obj, otn_oa_obj, otn_oa_id);
    
    auto& mgr = virtual_otn_device_manager::instance();
    auto * oa_dev = mgr.get_device<virtual_otn_oa_device>(obj->sai_object_id);
    if (!oa_dev)
    {
        logger::error(std::string(__func__) + ", device not found for object id " + std::to_string(otn_oa_id));
        return SAI_STATUS_ITEM_NOT_FOUND;
    }     

    switch (attr->id) {
    case SAI_OTN_OA_ATTR_NAME:
    {
        std::string name(attr->value.chardata);
        obj->dev_name = name;
        obj->dev_type = dev_util::get_dev_type(name);

        // TODO, set port name by name instead of reading from module
        obj->ingress_port = name + "-IN";
        obj->egress_port = name + "-OUT";

        //set name in virtual device 
        oa_dev->set_name(name);

        break;
    }
    case SAI_OTN_OA_ATTR_TYPE:
        // TODO, use type to support EDFA and RAMAN.
        obj->oa_type = attr->value.s32;
        oa_dev->set_type((sai_otn_oa_type_t)obj->oa_type);
        break;
    case SAI_OTN_OA_ATTR_TARGET_GAIN:
        obj->set_gain = attr->value.u32;

        //set into virtual device
        oa_dev->set_target_gain(attr->value.u32);
        break;
    case SAI_OTN_OA_ATTR_TARGET_GAIN_TILT:
        oa_dev->set_target_gain_tilt(attr->value.s32);
        break;
    case SAI_OTN_OA_ATTR_GAIN_RANGE:
        oa_dev->set_gain_range((sai_otn_oa_gain_range_t)attr->value.s32);
        break;
    case SAI_OTN_OA_ATTR_AMP_MODE:
    {
        obj->set_mode = attr->value.s32;
        //TODO figure out what virtual device needs to do in this case
        //int32_t val = obj->set_mode == SAI_OTN_OA_AMP_MODE_CONSTANT_POWER ? obj->set_power : obj->set_gain;
        oa_dev->set_amp_mode((sai_otn_oa_amp_mode_t)attr->value.s32);
        break;
    }
    case SAI_OTN_OA_ATTR_TARGET_OUTPUT_POWER:
    {
        obj->set_power = attr->value.s32;

        if (obj->set_mode == SAI_OTN_OA_AMP_MODE_CONSTANT_POWER) {
            //TODO figure out what virtual device is going to do in this case
            //rc = hal_set_oa_mode(obj->dev_type, obj->set_mode, obj->set_power);
        }
        oa_dev->set_target_output_power(attr->value.s32);
        break;
    }
    case SAI_OTN_OA_ATTR_ENABLED:
        oa_dev->set_enabled(attr->value.booldata);
        break;
    default:
        rc = SAI_STATUS_NOT_SUPPORTED;
        logger::warn("unsupported otn oa attribute, " + std::to_string(attr->id));
        break;
    }
    
    return rc;
}

sai_status_t
sai_adapter::get_otn_oa_attribute(sai_object_id_t otn_oa_id,
                                   uint32_t attr_count,
                                   sai_attribute_t *attr_list)
{
    logger::debug("enter " + std::string(__func__));

    CAST_OBJ(obj, otn_oa_obj, otn_oa_id);
    
    sai_status_t rc = SAI_STATUS_SUCCESS;

    auto& mgr = virtual_otn_device_manager::instance();
    auto * oa_dev = mgr.get_device<virtual_otn_oa_device>(obj->sai_object_id);
    if (!oa_dev)
    {
        logger::error(std::string(__func__) + ", device not found for object id " + std::to_string(otn_oa_id));
        return SAI_STATUS_ITEM_NOT_FOUND;
    } 

    for (uint32_t i = 0; i < attr_count; i++) {
        switch (attr_list[i].id) {
        case SAI_OTN_OA_ATTR_INGRESS_PORT:
            std::strncpy(attr_list[i].value.chardata, oa_dev->get_ingress_port().c_str(), sizeof(attr_list[i].value.chardata));
            break;
        case SAI_OTN_OA_ATTR_EGRESS_PORT:
            std::strncpy(attr_list[i].value.chardata, oa_dev->get_egress_port().c_str(), sizeof(attr_list[i].value.chardata));
            break;
        case SAI_OTN_OA_ATTR_ACTUAL_GAIN:
            attr_list[i].value.s32 = oa_dev->get_actual_gain();
            break;
        case SAI_OTN_OA_ATTR_ACTUAL_GAIN_TILT:
            attr_list[i].value.s32 = oa_dev->get_actual_gain_tilt();
            break;
        case SAI_OTN_OA_ATTR_INPUT_POWER_TOTAL:
        case SAI_OTN_OA_ATTR_INPUT_POWER_C_BAND:
        case SAI_OTN_OA_ATTR_INPUT_POWER_L_BAND:
        case SAI_OTN_OA_ATTR_OUTPUT_POWER_TOTAL:
        case SAI_OTN_OA_ATTR_OUTPUT_POWER_C_BAND:
        case SAI_OTN_OA_ATTR_OUTPUT_POWER_L_BAND:
        case SAI_OTN_OA_ATTR_LASER_BIAS_CURRENT:
        case SAI_OTN_OA_ATTR_OPTICAL_RETURN_LOSS:
            //currently just return the max output power for simulation purpose
            attr_list[i].value.s32 = oa_dev->get_max_output_power();
            break;

        default:
            rc = SAI_STATUS_NOT_SUPPORTED;
            logger::warn("unsupported otn oa attribute, " + std::to_string(attr_list[i].id));
            break;
        }
    }

    return rc;
}
