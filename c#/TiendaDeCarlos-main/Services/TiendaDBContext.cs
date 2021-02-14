using Microsoft.EntityFrameworkCore;
using TiendaDeCarlos.Models;

namespace TiendaDeCarlos.Services
{
    public class TiendaDBContext : DbContext
    {
        #region Contructor
        public TiendaDBContext(DbContextOptions<TiendaDBContext> options)
                    : base(options) { }
        #endregion Contructor

        #region Tablas
        public DbSet<ClienteModel> clientes {get; set;}
        public DbSet<CampesinoModel> campesinos {get; set;}
        public DbSet<ProductoModel> productos {get; set;}
        public DbSet<ComprasModel> compras {get; set;}
        #endregion Tablas
    }
}