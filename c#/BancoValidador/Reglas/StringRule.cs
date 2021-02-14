namespace BancoValidador.Reglas
{
    public class StringRule : IRule{
        public bool CheckValue(object value)
        {
           return  value is string;
        }
    }
}