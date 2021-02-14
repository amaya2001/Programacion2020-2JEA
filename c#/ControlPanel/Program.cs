using System;
using ControlPanel.Domain;
namespace ControlPanel
{
    class Program
    {
        static void Main(string[] args)
        {
            
            PanelDeControl panel = new PanelDeControl();
            panel.menu();



            /* Semilla s = new Semilla();
             Bodega bodega = new Bodega();

             s.Tipo = "Chia";
             s.CantidadAgua = 20;
             s.CantidadSombra = 50;
             s.Id = "1";

             bodega.addSemilla(s);

             int i;
             for (i = 0; i <= bodega.getListSemillas().Length - 1; i++)
             {
                 Console.WriteLine(i);
                 if (bodega.getListSemillas()[i] != null)
                 {
                     Console.WriteLine(bodega.getListSemillas()[i].toString());
                 }
             }


             Semilla s2 = new Semilla();


             s2.Tipo = "ppp";
             s2.CantidadAgua = 20;
             s2.CantidadSombra = 50;
             s2.Id = "2";

             bodega.addSemilla(s2);

             int j;
             for (j = 0; j <= bodega.getListSemillas().Length - 1; j++)
             {

                 if (bodega.getListSemillas()[j] != null)
                 {
                     Console.WriteLine(bodega.getListSemillas()[j].toString());
                 }
             }

             // Console.WriteLine(s.toString());
             Console.ReadLine();*/
        }
    }
}
