#ifndef INCLUDE_BACKENDS_CPU_BACKEND_H_
#define INCLUDE_BACKENDS_CPU_BACKEND_H_

#include <vector>
#include <string>

#include "backends/backend.h"
#include "backends/cpu_tensor.h"
#include "utils/blitz_cpu_function.h"
#include "utils/blitz_cpu_avx.h"

namespace blitz {

template<typename DType>
class Backend<CPUTensor, DType> {
 public:
  static void RectlinApplyFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output,
    DType slope);

  static void RectlinDerivativeFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output,
    DType slope);

  static void LogisticApplyFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output);

  static void LogisticDerivativeFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output);

  static void SoftmaxApplyFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output);

  static void SoftmaxDerivativeFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output);

  static DType SquareMeanApplyFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target);

  static void SquareMeanDerivativeFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target,
    CPUTensor<DType>* output);

  static DType AbsMeanApplyFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target);

  static void AbsMeanDerivativeFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target,
    CPUTensor<DType>* output);

  static DType CrossEntropyBinaryApplyFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target);

  static void CrossEntropyBinaryDerivativeFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target,
    CPUTensor<DType>* output);

  static DType CrossEntropyMultiApplyFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target);

  static void CrossEntropyMultiDerivativeFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* target,
    CPUTensor<DType>* output);

  static void BiasForwardFunc(
    const CPUTensor<DType>* input, const CPUTensor<DType>* bias,
    CPUTensor<DType>* output);

  static void BiasBackwardUpdateFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* update);

  static void BatchNormForwardFunc(
    const CPUTensor<DType>* input,
    const CPUTensor<DType>* gamma,
    const CPUTensor<DType>* beta,
    CPUTensor<DType>* input_var,
    CPUTensor<DType>* input_hat,
    CPUTensor<DType>* output,
    DType epsilon);

  static void BatchNormBackwardFunc(
    const CPUTensor<DType>* backward_input,
    const CPUTensor<DType>* forward_input_hat,
    const CPUTensor<DType>* forward_input_var,
    const CPUTensor<DType>* gamma,
    CPUTensor<DType>* gamma_update,
    CPUTensor<DType>* beta_update,
    CPUTensor<DType>* output,
    DType epsilon);

  static void GradientdescentFunc(
    CPUTensor<DType>* filter,
    CPUTensor<DType>* gradient,
    CPUTensor<DType>* velocity,
    DType momentum_coef,
    DType learning_rate,
    DType decay,
    size_t batch_size);

  static void MatrixMultiplyFunc(
    const CPUTensor<DType>* left,
    const CPUTensor<DType>* right,
    CPUTensor<DType>* output, 
    bool transa,
    bool transb,
    DType alpha,
    DType beta,
    BLITZ_ALGORITHM algorithm = BLITZ_BLAS_GEMM);

  static void Transpose2DFunc(
    const CPUTensor<DType>* input, CPUTensor<DType>* output);

  static void MaximumFunc(
    const CPUTensor<DType>* left, const CPUTensor<DType>* right,
    CPUTensor<DType>* output);

  static void MinusFunc(
    const CPUTensor<DType>* left, const CPUTensor<DType>* right,
    CPUTensor<DType>* output);

  static DType SumFunc(const CPUTensor<DType>* input);

  static void AddFunc(
    const CPUTensor<DType>* left, const CPUTensor<DType>* right,
    CPUTensor<DType>* output);

  static void MultiplyFunc(
    const CPUTensor<DType>* left, const CPUTensor<DType>* right,
    CPUTensor<DType>* output);

  static void MultiplyFunc(
    const CPUTensor<DType>* left, CPUTensor<DType>* output,
    DType right);

  static void Convolution2DForwardFunc(
    const CPUTensor<DType>* input,
    const CPUTensor<DType>* filter,
    CPUTensor<DType>* output,
    ConvolutionContext<CPUTensor, DType>* context);

  static void Convolution2DBackwardFunc(
    const CPUTensor<DType>* output,
    const CPUTensor<DType>* filter,
    CPUTensor<DType>* input,
    ConvolutionContext<CPUTensor, DType>* context);

  static void Convolution2DUpdateFunc(
    const CPUTensor<DType>* input,
    const CPUTensor<DType>* output,
    CPUTensor<DType>* update,
    ConvolutionContext<CPUTensor, DType>* context);

  static void MaxPooling2DForwardFunc(
    const CPUTensor<DType>* input,
    CPUTensor<DType>* output,
    CPUTensor<size_t>* max_index,
    size_t R, size_t S,
    size_t str_h, size_t str_w);

  static void MaxPooling2DBackwardFunc(
    const CPUTensor<DType>* output, 
    CPUTensor<DType>* input,
    const CPUTensor<size_t>* max_index);

  static void MakeBinaryMaskFunc(
    CPUTensor<DType>* output,
    DType low,
    DType high,
    DType keep);

  static void ConstantDistributionFunc(CPUTensor<DType>* output, DType val);

  static void NormalDistributionFunc(CPUTensor<DType>* output, DType loc, DType scale);

  static void UniformDistributionFunc(CPUTensor<DType>* output, DType low, DType high);

  static float EvaluateClassifyFunc(
    const CPUTensor<DType>* output, const CPUTensor<DType>* target);

  static float EvaluateRegressFunc(
    const CPUTensor<DType>* output, const CPUTensor<DType>* target);

  static void TransformCopyFunc(const CPUTensor<DType>* source, CPUTensor<DType>* dest);
  
  static void Unpack2DFunc(
    const CPUTensor<DType>* input,
    CPUTensor<DType>* unpack,
    size_t R, size_t S,
    size_t pad_h, size_t pad_w,
    size_t str_h, size_t str_w);

  static void Pack2DFunc(
    const CPUTensor<DType>* unpack,
    CPUTensor<DType>* input,
    size_t R, size_t S,
    size_t pad_h, size_t pad_w,
    size_t str_h, size_t str_w);

 private:
  static void Convolution2DForwardGEMMDispatch(
    const DType *unpack,
    const DType *output,
    DType *filter,
    size_t K, size_t PQ, size_t CRS,
    BLITZ_DATA_LAYOUT input_data_layout,
    BLITZ_DATA_LAYOUT output_data_layout);

  static void Convolution2DBackwardGEMMDispatch(
    const DType *filter,
    const DType *output,
    DType *unpack,
    size_t K, size_t PQ, size_t CRS,
    BLITZ_DATA_LAYOUT input_data_layout,
    BLITZ_DATA_LAYOUT output_data_layout);

  static void Convolution2DUpdateGEMMDispatch(
    const DType *unpack,
    const DType *output,
    DType *update,
    size_t K, size_t CRS, size_t PQ,
    BLITZ_DATA_LAYOUT input_data_layout,
    BLITZ_DATA_LAYOUT output_data_layout);

  static void Unpack2DDispatch(
    const DType *input,
    DType *unpack,
    size_t C, size_t H, size_t W,
    size_t R, size_t S,
    size_t P, size_t Q,
    size_t pad_h, size_t pad_w,
    size_t str_h, size_t str_w,
    BLITZ_DATA_LAYOUT input_data_layout);

  static void Pack2DDispatch(
    const DType *unpack,
    DType *input,
    size_t C, size_t H, size_t W,
    size_t R, size_t S,
    size_t P, size_t Q,
    size_t pad_h, size_t pad_w,
    size_t str_h, size_t str_w,
    BLITZ_DATA_LAYOUT input_data_layout);
};

}  // namespace blitz

#endif  // INCLUDE_BACKENDS_CPU_BACKEND_H_
