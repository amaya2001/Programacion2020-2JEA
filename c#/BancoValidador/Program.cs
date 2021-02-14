using System;
using BancoValidador.Balidator;
using BancoValidador.Reglas;

namespace BancoValidador
{
    class Program
    {
        static void Main(string[] args)
        {
            ValidateObject nombre = new ValidateObject()
            {
                value = "Juan"
            };

            nombre.Rules.Add( new StringRule());
            nombre.Rules.Add( new LenghtRule());

            if(nombre.ValidateField()){
                Console.WriteLine("Campo correcto");
            }else{
                Console.WriteLine("Campo fallido");
            }
        }
        }

    }

