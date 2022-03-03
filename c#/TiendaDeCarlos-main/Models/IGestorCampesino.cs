namespace TiendaDeCarlos.Models
{
    public interface IGestorCampesino
    {
        #region Methods
        void AgregarProducto(ProductoModel ProductoNuevo, CampesinoModel c1 )
        {
            c1.ProductoVendedor.Add(ProductoNuevo);
        }
        void EditarProducto(ProductoModel ProductoEditado )
        {
            
        }
        void EliminarProducto(ProductoModel ProductoEliminado )
        {

        }
        void GenerarRegistro(ProductoModel producto, ClienteModel c)
        {

        }
        #endregion Methods
    }
}