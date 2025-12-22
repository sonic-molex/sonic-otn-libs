#include "sai_adapter.h"

sai_status_t
sai_adapter::create_router_interface (sai_object_id_t *router_interface_id,
                                      sai_object_id_t switch_id,
                                      uint32_t attr_count,
                                      const sai_attribute_t *attr_list)
{
    router_interface_obj * obj = new router_interface_obj(switch_metadata_ptr->sai_id_map);

    *router_interface_id = obj->sai_object_id;
    logger::notice(std::string(__func__) + ", object id " + std::to_string(*router_interface_id));

    return SAI_STATUS_SUCCESS;
}

sai_status_t
sai_adapter::remove_router_interface (sai_object_id_t router_interface_id)
{
    logger::notice(std::string(__func__) + ", object id " + std::to_string(router_interface_id));

    switch_metadata_ptr->sai_id_map.free_id(router_interface_id);

    return SAI_STATUS_SUCCESS;
}

sai_status_t
sai_adapter::set_router_interface_attribute(sai_object_id_t router_interface_id, const sai_attribute_t *attr)
{
    return SAI_STATUS_NOT_IMPLEMENTED;
}

sai_status_t
sai_adapter::get_router_interface_attribute(sai_object_id_t router_interface_id, uint32_t attr_count, sai_attribute_t *attr_list)
{
    return SAI_STATUS_NOT_IMPLEMENTED;
}
