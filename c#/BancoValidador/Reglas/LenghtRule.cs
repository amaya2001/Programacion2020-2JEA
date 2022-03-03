namespace BancoValidador.Reglas
{
    public class LenghtRule : IRule{
        public bool CheckValue(object value)
        {
            string val = value as string;
                 return  val.Length >= 5;
        }
    }
}