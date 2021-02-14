using System.Collections.Generic;
using BancoValidador.Reglas;

namespace BancoValidador.Balidator
{
    public class ValidateObject{
        public object value { get; set; }
        public List<IRule> Rules { get; set; } 

        public ValidateObject(){
            Rules = new List<IRule>();
        }

        public bool ValidateField(){
            bool response = true;
            Rules.ForEach(r => {
                response = response && r.CheckValue(value);
            });
            return response;
        }
    }
}