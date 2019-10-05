#include <iostream>

using namespace std;

int truckStops(int distanciaViaje, int tamTanque, const int nGasolineras, int * arrayGasolineras, bool * arrayParadas);

int main()
{

    int distanciaViaje = 284;
    int tamTanque = 31+rand()%(51-31);;
	cout<<tamTanque<<endl;
    const int nGasolineras = 10;
    int arrayGasolineras[nGasolineras] = {30, 60, 90, 120, 152, 185, 214, 242, 273,284};
    bool arrayParadas[nGasolineras] = {false};
    int resultado = truckStops(distanciaViaje, tamTanque, nGasolineras, arrayGasolineras, arrayParadas);

    cout << "Numero de paradas: " << resultado << endl;

    if (resultado > -1)
    {
        for(int i = 0; i < nGasolineras; i++)
        {
            if (arrayParadas[i] == true)
            {
                cout << "Parada en la gasolinera del KM " << arrayGasolineras[i] << endl;
            }
        }
    } else {
        cout << "Si el resultado es -1, el camion no pudo completar el viaje ya que no hay gasolineras suficientes." << endl;
    }

    return 0;
}


int truckStops(int distanciaViaje, int tamTanque, const int nGasolineras, int * arrayGasolineras, bool * arrayParadas)
{
    int i = 0;
    int kmRecorridos = 0;
    int paradas = 0;
    int ultimaParada = 0;

    if (tamTanque < arrayGasolineras[0])
        return -1;

    while((ultimaParada + tamTanque < distanciaViaje) && (i <= nGasolineras - 1))
    {
        kmRecorridos = arrayGasolineras[i] - ultimaParada;
        if(kmRecorridos > tamTanque)
        {
            ultimaParada = arrayGasolineras[i-1];
            arrayParadas[i-1] = true;
            paradas++;
            kmRecorridos = 0;
        }
        i++;
    }

    if (ultimaParada + tamTanque >= distanciaViaje)
    {
        return paradas;
    } else {
        return -1;
    }
}
