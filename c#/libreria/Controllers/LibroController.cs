using Microsoft.AspNetCore.Mvc;


namespace libreria.Controllers
{
    [Route("[controller]")]
    public class LibroController : Controller
    {
        [HttpGet("ListaLibros")]
           public IActionResult Index()
        {
            return View();
        }

    }
}