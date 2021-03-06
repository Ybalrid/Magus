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

#ifndef MAGUS_GENERIC_FUNCTIONS_H
#define MAGUS_GENERIC_FUNCTIONS_H

#include <QString>

//****************************************************************************/
// Util function to determine whether a file is of type 'image, based on the file extenstion
static bool isImageBasedOnExtension(const QString& fileName)
{
    int lastPoint = fileName.lastIndexOf(".");
    if (lastPoint > 0)
    {
        QString ext[] = {"bmp", "ico", "jpg", "jif", "jpeg", "jpe", "jng", "koa", "iff", "lbm", "mng", "pbm", "pbm", "pcd", "pcx", "pgm", "pgm", "png", "ppm", "ppm", "ras", "tga", "targa", "tif", "tiff", "wap", "wbmp", "wbm", "psd", "cut", "xbm", "xpm", "gif", "hdr", "g3", "sgi", "exr", "j2k", "j2c", "jp2", "pfm", "pct", "pict", "pic", "dds"};
        QString extension = fileName.right(fileName.length() - lastPoint - 1);
        extension.toLower();
        for (int i = 0; i < 45; ++i)
            if (extension == ext[i])
                return true;
    }

    return false;
};


#endif
