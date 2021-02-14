namespace TiendaDeCarlos.Models
{
    public interface IGestorClienteModel
    {
        #region Methods
        void AñadirProductoCarrito(ProductoModel ProductoComprar )
        {
        }
        void PagarProducto(ProductoModel ProductoComprado )
        {
        }
        void EliminarProductoCarrito(ProductoModel ProductoNoDeseado )
        {
        }
        #endregion Methods
    }
}