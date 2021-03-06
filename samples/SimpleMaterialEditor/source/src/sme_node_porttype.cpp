
/****************************************************************************
**
** Copyright (C) 2014
**
** This file is generated by the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

// Include
#include "sme_node_porttype.h"

namespace Magus
{
    //****************************************************************************/
    QtMaterialInPortType::QtMaterialInPortType(void) : QtPortType()
    {
        mPortType = 10;
    }

    //****************************************************************************/
    QtMaterialOutPortType::QtMaterialOutPortType(void) : QtPortType()
    {
        mPortType = 11;
    }

    //****************************************************************************/
    QtTechniqueInPortType::QtTechniqueInPortType(void) : QtPortType()
    {
        mPortType = 12;
    }

    //****************************************************************************/
    QtTechniqueOutPortType::QtTechniqueOutPortType(void) : QtPortType()
    {
        mPortType = 13;
    }

    //****************************************************************************/
    QtPassInPortType::QtPassInPortType(void) : QtPortType()
    {
        mPortType = 14;
    }

    //****************************************************************************/
    QtPassOutPortType::QtPassOutPortType(void) : QtPortType()
    {
        mPortType = 15;
    }

    //****************************************************************************/
    QtTextureUnitInPortType::QtTextureUnitInPortType(void) : QtPortType()
    {
        mPortType = 16;
    }

    //****************************************************************************/
    QtTextureUnitOutPortType::QtTextureUnitOutPortType(void) : QtPortType()
    {
        mPortType = 17;
    }
}
