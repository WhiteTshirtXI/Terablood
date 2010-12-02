// --------------------------------------------------------------
// Implementación de condiciones de frontera
// Terminado Octubre 09 - 2010
// --------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../include/fronteras.h"

using namespace std;

void velNodoSuperior(Real g[19], Real f[19], Real U, Real V, Real W)
{
	// Calculate new distributions functions
	g=f;
	Real A=0.0, B=0.0, rho=0.0, Nx=0.0, Ny=0.0;
    A=f[0]+f[1]+f[2]+f[3]+f[6]+f[10]+f[11]+f[7]+f[18];
    B=f[4]+f[8]+f[12]+f[14]+f[16];
    rho = (A+2.*B)/(W+1.);
    
   	Nx=(1./2.)*(f[0]+f[6]+f[7]-(f[1]+f[10]+f[11]))-(1./3.)*rho*U;
    Ny=(1./2.)*(f[2]+f[6]+f[10]-(f[3]+f[7]+f[11]))-(1./3.)*rho*V;
    
    g[5]=f[4]-(1./3.)*rho*W;
    g[9]=f[12]+(rho/6.)*(-W+U)-Nx;
    g[13]=f[8]+(rho/6.)*(-W-U)+Nx;
    g[15]=f[16]+(rho/6.)*(-W+V)-Ny;
    g[17]=f[14]+(rho/6.)*(-W-V)+Ny;
}

void velNodoInferior(Real g[19], Real f[19], Real U, Real V, Real W)
{
	// Calculate new distributions functions
	g=f;
	Real A=0.0, B=0.0, rho=0.0, Nx=0.0, Ny=0.0;
	A=f[0]+f[1]+f[2]+f[3]+f[6]+f[7]+f[10]+f[11]+f[18];
	B=f[5]+f[9]+f[13]+f[15]+f[17];
    rho = (A+2.*B)/(1.-W);
    
    Nx=(1./2.)*(f[0]+f[6]+f[7]-(f[1]+f[10]+f[11]))-(1./3.)*rho*-U;
    Ny=(1./2.)*(f[2]+f[6]+f[10]-(f[3]+f[7]+f[11]))-(1./3.)*rho*V;
    
    g[4]=f[5]+(1./3.)*rho*W;
    g[8]=f[13]+(rho/6.)*(W-U)-Nx;
    g[12]=f[9]+(rho/6.)*(W+U)+Nx;
    g[14]=f[17]+(rho/6.)*(W+V)-Ny;
    g[16]=f[15]+(rho/6.)*(W-V)+Ny;
}

void velNodoIzquierdo(Real g[19], Real f[19], Real U, Real V, Real W)
{
	// Calculate new distributions functions
	g=f;
	Real A=0.0, B=0.0, rho=0.0, xNy=0.0, xNz=0.0;
    A=f[2]+f[3]+f[4]+f[5]+f[14]+f[15]+f[16]+f[17]+f[18];
    B=f[1]+f[10]+f[11]+f[12]+f[13];
    rho = (A+2.*B)/(U+1.);
    
   	xNy=(1./2.)*(f[2]+f[14]+f[15]-(f[3]+f[16]+f[17]))-(1./3.)*rho*V;
    xNz=(1./2.)*(f[4]+f[16]+f[14]-(f[5]+f[15]+f[18]))-(1./3.)*rho*W;
    
    g[0]=f[1]-(1./3.)*rho*U;
    g[7]=f[10]+(rho/6.)*(U-V)-xNy;
    g[6]=f[11]+(rho/6.)*(U+V)-xNy;
    g[8]=f[13]+(rho/6.)*(U+W)-xNz;
    g[9]=f[12]+(rho/6.)*(U-W)+xNz;
}

void velNodoDerecho(Real g[19], Real f[19], Real U, Real V, Real W)
{
	// Calculate new distributions functions
	g=f;
	Real A=0.0, B=0.0, rho=0.0, xNy=0.0, xNz=0.0;
    A=f[2]+f[3]+f[4]+f[5]+f[14]+f[15]+f[16]+f[17]+f[18];
    B=f[1]+f[10]+f[11]+f[12]+f[13];
    rho = (A+2*B)/(U+1);
    
   	xNy=(1./2.)*(f[2]+f[14]+f[15]-(f[3]+f[16]+f[17]))-(1./3.)*rho*V;
    xNz=(1./2.)*(f[4]+f[16]+f[14]-(f[5]+f[15]+f[18]))-(1./3.)*rho*W;
    
    g[0]=f[1]-(1./3.)*rho*U;
    g[7]=f[10]+(rho/6.)*(U-V)-xNy;
    g[6]=f[11]+(rho/6.)*(U+V)-xNy;
    g[8]=f[13]+(rho/6.)*(U+W)-xNz;
    g[9]=f[12]+(rho/6.)*(U-W)+xNz;
}
