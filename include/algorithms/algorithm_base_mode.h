/* file: algorithm_base_mode.h */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of base classes defining algorithm interface.
//--
*/

#ifndef __ALGORITHM_BASE_MODE_H__
#define __ALGORITHM_BASE_MODE_H__

#include "services/daal_memory.h"
#include "services/daal_kernel_defines.h"
#include "services/error_handling.h"
#include "services/env_detect.h"
#include "algorithms/algorithm_types.h"

namespace daal
{
namespace algorithms
{
namespace interface1
{

/**
 * @addtogroup base_algorithms
 * @{
 */

/**
 * <a name="DAAL-CLASS-ALGORITHMS__ALGORITHM"></a>
 * \brief Implements the abstract interface AlgorithmIface. Algorithm is, in turn, the base class
 *         for the classes interfacing the major stages of data processing: Analysis, Training and Prediction.
 * \tparam mode Computation mode of the algorithm, \ref ComputeMode
 */
template<ComputeMode mode> class Algorithm : public AlgorithmIfaceImpl
{
public:
    /** Default constructor */
    Algorithm() : _ac(0), _in(0), _pres(0), _res(0), _par(0)
    {
        getEnvironment();
    };

    virtual ~Algorithm()
    {
        if(_ac)
        {
            delete _ac;
        }
    }

    virtual void clean() {}

    /**
    * Returns method of the algorithm
    * \return Method of the algorithm
    */
    virtual int getMethod() const = 0;

    /**
     * Validates result parameters of the finalizeCompute method
     */
    virtual void checkPartialResult() = 0;

    /**
     * Validates parameters of the finalizeCompute method
     */
    virtual void checkFinalizeComputeParams() = 0;

protected:
    PartialResult *allocatePartialResultMemory()
    {
        if(_pres == 0)
        {
            allocatePartialResult();
        }

        return _pres;
    }

    virtual void setParameter() {}

    void allocateInputMemory()
    {
        allocateInput();
    }

    void allocateResultMemory()
    {
        if(_res == 0)
        {
            allocateResult();
        }
    }

    void initPartialResult()
    {
        initializePartialResult();
    }


    virtual void allocateInput() {};
    virtual void allocatePartialResult() = 0;
    virtual void allocateResult() = 0;

    virtual void initializePartialResult() = 0;
    virtual Algorithm<mode> *cloneImpl() const = 0;

    bool getInitFlag() { return _pres->getInitFlag(); }
    void setInitFlag(bool flag) { _pres->setInitFlag(flag); }

    AlgorithmContainerIface<mode> *_ac;

    Input         *_in;
    PartialResult *_pres;
    Result        *_res;
    Parameter     *_par;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__ALGORITHM"></a>
 * \brief Implements the abstract interface AlgorithmIface. Algorithm<batch> is, in turn, the base class
 *        for the classes interfacing the major stages of data processing in %batch mode:
 *        Analysis<batch>, Training<batch> and Prediction.
 */
template<> class Algorithm<batch> : public AlgorithmIfaceImpl
{
public:
    /** Default constructor */
    Algorithm(): _ac(0), _par(0), _in(0), _res(0)
    {
        getEnvironment();
    };

    virtual ~Algorithm()
    {
        if(_ac)
        {
            delete _ac;
        }
    }

    /**
     * Validates parameters of the compute method
     */
    virtual void checkComputeParams() = 0;

protected:
    void allocateInputMemory()
    {
        allocateInput();
    }

    void allocateResultMemory()
    {
        if(_res == 0)
        {
            allocateResult();
        }
    }

    virtual void setParameter() {}

    virtual void allocateResult() = 0;
    virtual void allocateInput() {};

    virtual Algorithm<batch> *cloneImpl() const = 0;

    daal::algorithms::AlgorithmContainerIface<batch> *_ac;

    Parameter *_par;
    Input     *_in;
    Result    *_res;
};

/** @} */
} // namespace interface1
using interface1::Algorithm;

}
}
#endif
