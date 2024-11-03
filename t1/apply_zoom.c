//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//      apply_zoom.c                                                            //
//      Descricao: Realiza leitura de um arquivo .ppm e aplica um zoom x3       //
//      Criado por: Thiago de Souza Cardoso             Github: @magotiti       //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "lib_ppm.h"

#define ZOOM 3 // tamanho do zoom

void apply_zoom(struct image_s *input, struct image_s *output)
{

    for (int y = 0; y < input->height; y++)
    {
        for (int x = 0; x < input->width; x++)
        {
            struct pixel_s *pixel = &input->pix[y * input->width + x];

            unsigned char red[ZOOM][ZOOM] = {{0}};
            unsigned char green[ZOOM][ZOOM] = {{0}};
            unsigned char blue[ZOOM][ZOOM] = {{0}};

            if (pixel->r <= 74)
            {
                // tudo preto
            }
            else if (pixel->r >= 75 && pixel->r <= 134)
            {
                red[1][0] = 1;
            }
            else if (pixel->r >= 135 && pixel->r <= 179)
            {
                red[0][0] = 1;
                red[2][0] = 1;
            }
            else
            {
                red[0][0] = 1;
                red[1][0] = 1;
                red[2][0] = 1;
            }

            if (pixel->g <= 74)
            {
                // tudo preto
            }
            else if (pixel->g >= 75 && pixel->g <= 134)
            {
                green[1][1] = 1;
            }
            else if (pixel->g >= 135 && pixel->g <= 179)
            {
                green[0][1] = 1;
                green[2][1] = 1;
            }
            else
            {
                green[0][1] = 1;
                green[1][1] = 1;
                green[2][1] = 1;
            }

            if (pixel->b <= 74)
            {
                // tudo preto
            }
            else if (pixel->b >= 75 && pixel->b <= 134)
            {
                blue[1][2] = 1;
            }
            else if (pixel->b >= 135 && pixel->b <= 179)
            {
                blue[0][2] = 1;
                blue[2][2] = 1;
            }
            else
            {
                blue[0][2] = 1;
                blue[1][2] = 1;
                blue[2][2] = 1;
            }

            for (int y2 = 0; y2 < ZOOM; y2++)
            {
                for (int x2 = 0; x2 < ZOOM; x2++)
                {
                    struct pixel_s *zoom_pixel = &output->pix[(y * ZOOM + y2) * output->width + (x * ZOOM + x2)];

                    if (red[y2][x2])
                    {
                        zoom_pixel->r = 255;
                    }
                    else
                    {
                        zoom_pixel->r = 0;
                    }

                    if (green[y2][x2])
                    {
                        zoom_pixel->g = 255;
                    }
                    else
                    {
                        zoom_pixel->g = 0;
                    }

                    if (blue[y2][x2])
                    {
                        zoom_pixel->b = 255;
                    }
                    else
                    {
                        zoom_pixel->b = 0;
                    }
                }
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    struct image_s input_image, output_image;
    int result;

    result = read_ppm("lena.ppm", &input_image);
    if (result != 0)
    {
        printf("erro ao ler a imagem\n");
        return 1;
    }

    output_image.width = input_image.width * ZOOM;
    output_image.height = input_image.height * ZOOM;
    output_image.pix = malloc(output_image.width * output_image.height * sizeof(struct pixel_s));

    if (output_image.pix == NULL)
    {
        printf("erro ao alocar memoria para a imagem\n");
        free_ppm(&input_image);
        return 1;
    }

    apply_zoom(&input_image, &output_image);

    result = write_ppm("output_lena.ppm", &output_image);
    if (result != 0)
    {
        printf("erro ao salvar a imagem\n");
        free_ppm(&input_image);
        free_ppm(&output_image);
        return 1;
    }

    free_ppm(&input_image);
    free(output_image.pix);

    printf("zoom aplicado na imagem.\n");
    return 0;
}
