namespace  Ej1
{

    public class Lapiz
    {
        #region Atributos

        public double LongitudPunta { get; set; }
        public double LongitudCuerpo { get; set; }

        #endregion Atributos

        #region Metodos

        public void SacarPunta( int vueltas )
        {
            for( int i = 0; i <= vueltas; i++ ){
                AumentarPunta();
                DisminuirCuerpo();
            }

        }
        #endregion Metodos

        #region Comportamientos

        private void AumentarPunta()
        {
            LongitudPunta += 0.5;
        }

        private void DisminuirCuerpo()
        {
            LongitudCuerpo -= 0.5;
        }
        #endregion Comportamientos


    }

}