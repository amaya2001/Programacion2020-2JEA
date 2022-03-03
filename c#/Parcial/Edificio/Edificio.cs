using Parcial.Salones;
using System;

namespace Parcial.Edificio
{
    public class Edificios{
        list<Salon> listSalones = new list<Salon>();
        //list<Salones> listSalones = new List<Salones>();
        public int TiempoAbierto { get; set; }

        public int TiempoLuzOn { get; set; }

        public int TiempoLuzOff { get; set; }

        public int TemperaturaAc { get; set; }

        public Salones Sal = null; // Propiedad para la agregacion
    
        public Edificios( list<Salones> listSalones, int TiempoAbierto, int TiempoLuzOn, int TiempoLuzOff, int TemperaturaAc ){
            Salones = _salones;
            TiempoAbierto = _tiempoAbierto;
            TiempoLuzOn = _tiempoLuzOn;
            TiempoLuzOff = _tiempoLuzOff;
            TemperaturaAc = 23; //Los grados a los que se debe mantener el sistema
        }
    }
}