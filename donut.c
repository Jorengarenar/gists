#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI  3.14159265358979323846
const float I[][3] = { { 1,0,0 }, { 0,1,0 }, { 0,0,1 } }; // identity matrix

void allocBuffers(int X, int Y, float** zbuffer, char** output);
void vec_x_mat3(const float v[], const float m[][3], float res[]);

int msleep(long msec);

int main()
{
    const char* symbols = ".,-~:;=!*#$@";

    float A = 0, B = 0;

    float R1 = 1, R2 = 5;
    float K2 = 3*R1*R2;

    float* zbuffer = NULL;
    char* output = NULL;

    int X = 80, Y = 22; // window width, window height

    float K1 = X*K2/(8*(R1+R2));

    while (1) {
        allocBuffers(X, Y, &zbuffer, &output);

        for (float theta = 0; theta < 2*PI; theta += 0.07) {
            for (float phi = 0; phi < 2*PI; phi += 0.02) {

                // trgionometric values
                float sinA = sin(A), cosA = cos(A), sinB = sin(B), cosB = cos(B),
                      sinTheta = sin(theta), cosTheta = cos(theta),
                      sinPhi = sin(phi), cosPhi = cos(phi);

                // transformation matrices
                float m1[][3] = { // rotate CIRCLE around y-axis to produce torus
                    {  cosPhi, 0, sinPhi },
                    {       0, 1,      0 },
                    { -sinPhi, 0, cosPhi },
                };
                float m2[][3] = { // spin TORUS around the x-axis by angle A
                    { 1,     0,    0 },
                    { 0,  cosA, sinA },
                    { 0, -sinA, cosA },
                };
                float m3[][3] = { // spin TORUS around the z-axis by angle B
                    {  cosB, sinB, 0 },
                    { -sinB, cosB, 0 },
                    {     0,    0, 1 },
                };
                float m4[][3] = { // scale (to correct "roundness")
                    { 2, 0, 0 },
                    { 0, 1, 0 },
                    { 0, 0, 1 }
                };

                float V[4][3]; // buf vectors

                #define multiply(vec) \
                    vec_x_mat3(vec,  m1, V[0]); \
                    vec_x_mat3(V[0], m2, V[1]); \
                    vec_x_mat3(V[1], m3, V[2]); \
                    vec_x_mat3(V[2], m4, V[3]);

                float v1[3] = { R2 + R1*cosTheta, R1* sinTheta, 0 };
                multiply(v1);
                float x = V[3][0], y = V[3][1], z = V[3][2];

                float D = 1/(K2+z);

                int xp = (int) (X/2 + (K1*x)*D);
                int yp = (int) (Y/2 + (K1*y)*D);
                int k = xp + X*yp;

                float v2[3] = { cosTheta, sinTheta, 0 };
                multiply(v2);
                float Nx = V[3][0], Ny = V[3][1], Nz = V[3][2];

                float L = Ny - Nz; // (Nx,Ny,Nz)*(0,1,−1)
                int l = L > 0 ? L*8 : 0; // luminance index

                if (k > 0 && k < X*Y && D > zbuffer[k]) {
                    zbuffer[k] = D;
                    output[k] = symbols[l];
                }
            }
        }

        A += 0.04;
        B += 0.02;

        printf("\x1b[H %s", output);
        free(output);
        free(zbuffer);
        msleep(100);
    }
}

void allocBuffers(int X, int Y, float** zbuffer, char** output)
{
    const int bufSiz = X*Y;
    *zbuffer = malloc(bufSiz * sizeof(**zbuffer));
    *output  = malloc(bufSiz * sizeof(**output) + 1);
    (*output)[bufSiz] = '\0';
    memset(*output, ' ', bufSiz);
    memset(*zbuffer, 0,  bufSiz * sizeof(**zbuffer));
    for (int i = X; i < bufSiz+1; i += X) {
        (*output)[i] = '\n';
    }
}

void vec_x_mat3(const float v[], const float m[][3], float res[])
{
    for (int i = 0; i < 3; ++i) {
        res[i] = 0;
        for (int j = 0; j < 3; ++j) {
            res[i] += v[j] * m[j][i];
        }
    }
}

int msleep(long msec)
{
    struct timespec ts;
    int res;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res);

    return res;
}
