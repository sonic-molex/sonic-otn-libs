#pragma once

#include "saiextensions.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *S_O_Handle;

S_O_Handle create_sai_adapter();

void free_sai_adapter(S_O_Handle);

sai_status_t sai_adapter_api_query(S_O_Handle, sai_api_t, void **);

sai_object_type_t sai_adapter_object_type_query(S_O_Handle, sai_object_id_t);

#ifdef __cplusplus
}
#endif

