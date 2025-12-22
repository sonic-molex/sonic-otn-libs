#include "sai_hal_helper.h"

// OTAI OTDR

sai_status_t
sai_adapter::create_otn_otdr(sai_object_id_t *otn_otdr_id,
                             sai_object_id_t switch_id,
                             uint32_t attr_count,
                             const sai_attribute_t *attr_list)
{
    CHECK_SWITCH_ID(switch_id);

    otn_otdr_obj *obj = new otn_otdr_obj(switch_metadata_ptr->sai_id_map);
    *otn_otdr_id = obj->sai_object_id;
    (*logger)->info("create_otn_otdr, object_id {}", obj->sai_object_id);

    for (uint32_t i = 0; i < attr_count; i++) {
        set_otn_otdr_attribute(obj->sai_object_id, attr_list + i);
    }

    return SAI_STATUS_SUCCESS;
}

sai_status_t
sai_adapter::remove_otn_otdr(sai_object_id_t otn_otdr_id)
{
    (*logger)->info("remove_otn_otdr");
    switch_metadata_ptr->sai_id_map.free_id(otn_otdr_id);
    return SAI_STATUS_SUCCESS;
}

sai_status_t
sai_adapter::set_otn_otdr_attribute(sai_object_id_t otn_otdr_id,
                                    const sai_attribute_t *attr)
{
    sai_status_t rst = SAI_STATUS_SUCCESS;
    (*logger)->info("set_otn_otdr_attribute, attr id {}", attr->id);

    CAST_OBJ(obj, otn_otdr_obj, otn_otdr_id);

#if 0
    COtdrCfgData cfg = {0};
    sai_status_t rst = hal_get_otdr_cfg_data(obj->dev_type, (void *)&cfg);
    if (SAI_STATUS_SUCCESS != rst) {
        return rst;
    }
#endif

    switch (attr->id) {
    case SAI_OTN_OTDR_ATTR_ID:
    {
        id_manager idm(attr->value.u32, SAI_OBJECT_TYPE_OTN_OTDR);
        obj->dev_type = idm.is_first_slot() ? DEV_TYPE_OTDR : DEV_TYPE_P_OTDR;
        break;
    }
    case SAI_OTN_OTDR_ATTR_REFLECTION_THRESHOLD:
        obj->reflect_thr = attr->value.d64;
        rst = hal_set_otdr_thr(obj->dev_type, obj->reflect_thr, obj->splice_los_thr, obj->fiber_end_thr);
        break;
    case SAI_OTN_OTDR_ATTR_SPLICE_LOSS_THRESHOLD:
        obj->splice_los_thr = attr->value.d64;
        rst = hal_set_otdr_thr(obj->dev_type, obj->reflect_thr, obj->splice_los_thr, obj->fiber_end_thr);
        break;
    case SAI_OTN_OTDR_ATTR_END_OF_FIBER_THRESHOLD:
        obj->fiber_end_thr = attr->value.d64;
        rst = hal_set_otdr_thr(obj->dev_type, obj->reflect_thr, obj->splice_los_thr, obj->fiber_end_thr);
        break;
    case SAI_OTN_OTDR_ATTR_DISTANCE_RANGE:
        obj->distance_range = attr->value.u32;
        rst = hal_set_otdr_param(obj->dev_type, obj->distance_range, obj->pulse_width, obj->sample_res);
        break;
    case SAI_OTN_OTDR_ATTR_PULSE_WIDTH:
        obj->pulse_width = attr->value.u32;
        rst = hal_set_otdr_param(obj->dev_type, obj->distance_range, obj->pulse_width, obj->sample_res);
        break;
    case SAI_OTN_OTDR_ATTR_AVERAGE_TIME:
        rst = hal_set_otdr_time(obj->dev_type, attr->value.u32);
        break;
    case SAI_OTN_OTDR_ATTR_SCAN:
        break;
    default:
        (*logger)->info("unsupported otai otdr attribute {}", attr->id);
        break;
    }

    return rst;
}

sai_status_t
sai_adapter::get_otn_otdr_attribute(sai_object_id_t otn_otdr_id,
                                    uint32_t attr_count,
                                    sai_attribute_t *attr_list)
{
    sai_status_t rst = SAI_STATUS_SUCCESS;
    (*logger)->info("get_otn_otdr_attribute");

    CAST_OBJ(obj, otn_otdr_obj, otn_otdr_id);

    for (uint32_t i = 0; i < attr_count; i++) {
        switch (attr_list[i].id) {
        case SAI_OTN_OTDR_ATTR_SAMPLING_RESOLUTION:
            attr_list[i].value.d64 = obj->sample_res;
            break;
        case SAI_OTN_OTDR_ATTR_SCANNING_STATUS:
        {
            COtdrStatusData sta = {0};
            rst = hal_get_otdr_status_data(obj->dev_type, (void *)&sta);
            attr_list[i].value.u32 = sta.ulScanStatus;
            break;
        }
        default:
            (*logger)->info("unsupported otai otdr attribute {}", attr_list[i].id);
            break;
        }
    }

    return rst;
}
