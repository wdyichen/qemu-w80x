#ifndef __NNE_MODEL_WRAP_H__
#define __NNE_MODEL_WRAP_H__

#ifdef __cplusplus
extern "C" {
#endif

// conv 
void thead_asp_nne_conv_op_wrap(uint32_t idtype, 
        uint32_t odtype, 
        const uint16_t input_depth,   
        const uint16_t output_depth, 
        const uint16_t input_height,  
        const uint16_t output_height, 
        const uint16_t input_width, 
        const uint16_t output_width, 
        const uint8_t filter_height, 
        const uint8_t filter_width,
        const uint8_t stride_height, 
        const uint8_t stride_width,
        const uint16_t padding_height, 
        const uint16_t padding_width,
        const uint8_t batchs,
        const int32_t weights_offset,
        const int32_t output_offset,
        const int32_t output_multiplier,
        const int32_t output_shift,
        const int32_t quantized_activation_min,
        const int32_t quantized_activation_max,
        const uint16_t input_line_stride,
        const uint32_t input_surface_stride,
        const uint16_t filter_line_stride,
        const uint32_t filter_surface_stride,
        const uint32_t filter_kernel_stride,
        const uint16_t output_line_stide,
        const uint32_t output_surface_stride,
        const int32_t* output_multiplier_p, 
        const int8_t* output_shift_p,  
        const void* input_data, 
        const void* filter_data,
        const void* bias_data, 
        void* output_data);

// dw conv
void thead_asp_nne_dw_conv_op_wrap( uint32_t idtype, 
        uint32_t odtype, 
        const uint16_t input_depth,   
        const uint16_t output_depth, 
        const uint16_t input_height,  
        const uint16_t output_height, 
        const uint16_t input_width, 
        const uint16_t output_width, 
        const uint8_t filter_height, 
        const uint8_t filter_width,
        const uint8_t stride_height, 
        const uint8_t stride_width,
        const uint16_t padding_height, 
        const uint16_t padding_width,
        const uint8_t batchs,
        const int32_t weights_offset,
        const int32_t output_offset,
        const int32_t output_multiplier,
        const int32_t output_shift,
        const int32_t quantized_activation_min,
        const int32_t quantized_activation_max,
        const uint16_t input_line_stride,
        const uint32_t input_surface_stride,
        const uint16_t filter_line_stride,
        const uint32_t filter_surface_stride,
        const uint32_t filter_kernel_stride,
        const uint16_t output_line_stide,
        const uint32_t output_surface_stride,
        const int32_t* output_multiplier_ptr, 
        const int8_t* output_shift_ptr,  
        const void* input_data, 
        const void* filter_data,
        const void* bias_data, 
        void* output_data);       

// fc op                            
void thead_asp_nne_fc_op_wrap(uint32_t idtype, 
        uint32_t odtype, 
        const uint16_t input_depth, 
        const uint16_t output_depth,
        const uint8_t batchs,
        const int32_t weights_offset,
        const int32_t output_offset,
        const int32_t output_multiplier,
        const int32_t output_shift,
        const int32_t quantized_activation_min,
        const int32_t  quantized_activation_max,
        const uint16_t input_line_stride,
        const uint16_t filter_line_stride,
        const uint16_t output_line_stride,
        const void* input_data, 
        const void* filter_data,
        const void* bias_data, 
        void* output_data);

// max pool
void thead_asp_nne_max_pool_op_wrap(uint32_t idtype, 
        uint32_t odtype, 
        const uint16_t input_depth,   
        const uint16_t output_depth, 
        const uint16_t input_height,  
        const uint16_t output_height, 
        const uint16_t input_width, 
        const uint16_t output_width, 
        const uint8_t filter_height, 
        const uint8_t filter_width,
        const uint8_t stride_height, 
        const uint8_t stride_width,
        const uint16_t padding_height, 
        const uint16_t padding_width,
        const uint8_t batchs,
        const int32_t quantized_activation_min,
        const int32_t quantized_activation_max,
        const uint16_t input_line_stride,
        const uint32_t input_surface_stride,
        const uint16_t output_line_stide,
        const uint32_t output_surface_stride,
        const void* input_data, 
        void* output_data);

// ave pool                                   
void thead_asp_nne_ave_pool_op_wrap(uint32_t idtype, 
        uint32_t odtype, 
        const uint16_t input_depth,   
        const uint16_t output_depth, 
        const uint16_t input_height,  
        const uint16_t output_height, 
        const uint16_t input_width, 
        const uint16_t output_width, 
        const uint8_t filter_height, 
        const uint8_t filter_width,
        const uint8_t stride_height, 
        const uint8_t stride_width,
        const uint16_t padding_height, 
        const uint16_t padding_width,
        const uint8_t batchs,
        const int32_t quantized_activation_min,
        const int32_t quantized_activation_max,
        const uint16_t input_line_stride,
        const uint32_t input_surface_stride,
        const uint16_t output_line_stide,
        const uint32_t output_surface_stride,
        const void* input_data, 
        void* output_data);

#ifdef __cplusplus
}
#endif

#endif  // __NNE_MODEL_WRAP_H__
