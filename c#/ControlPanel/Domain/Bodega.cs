using ControlPanel.Domain;
using System;
namespace ControlPanel.Domain
{
    public class Bodega
    {


        public int IdBodega { get; set; }
        public string Nombre { get; set; }
        public Semilla[] ListaSemillas = new Semilla[1];


        public Bodega()
        {

        }

        public void setListSemillas(Semilla[] ListaSemillas)
        {
            this.ListaSemillas = ListaSemillas;
        }

        public Semilla[] getListSemillas()
        {
            return this.ListaSemillas;
        }


        public void addSemilla(Semilla semilla)
        {
            Semilla[] ListaSemillastemp = new Semilla[ListaSemillas.Length];        
            this.ListaSemillas[ListaSemillas.Length - 1] = semilla;
            int i;
            for (i = 0; i < ListaSemillas.Length; i++)
            {
                ListaSemillastemp[i] = this.ListaSemillas[i];
                Console.WriteLine("i" + i);
            }
            this.ListaSemillas = new Semilla[ListaSemillastemp.Length + 1];
            int j;
            for (j = 0; j < ListaSemillastemp.Length; j++)
            {
                this.ListaSemillas[j] = ListaSemillastemp[j];              
            }
            
        }

    }




}