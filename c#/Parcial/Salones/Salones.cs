using System;
using Parcial.Edificio;

namespace Parcial.Salones
{
    public class Salon{
        public bool LuzSalon { get; set; }

        public int TempSalon { get; set; }

        public bool Habilitado { get; set; }

        public bool Abierto { get; set; }

        public bool Ac { get; set; }

        public string NombreSalon { get; set; }

        list<Reservas> listReservas = new list<Reservas>(); // lista de reservas

        public Reservas reserva1 = null;

        public Salon( bool LuzSalon, int TempSalon, bool Habilitado, bool Abierto, bool Ac, string NombreSalon,  list<Reservas> listReservas ){
            LuzSalon = _luzSalon;
            TempSalon =_tempSalon;
            Habilitado = _habilitado;
            Abierto = _abierto;
            Ac = _ac;
            NombreSalon = _nombreSalon;
            listReservas = _listReservas;
        }

        void MositrarReservados(){

        foreach (int reserva in listReservas)
        {
            Console.Write($"{reserva} ");
        }
        Console.WriteLine();
        }
    }
}