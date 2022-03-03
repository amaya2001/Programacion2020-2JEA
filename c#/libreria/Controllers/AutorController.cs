using Microsoft.AspNetCore.Mvc;

namespace libreria.Controllers
{
    public class AutorController : Controller
    {
           public IActionResult Index()
        {
            return View();
        }

    }
}