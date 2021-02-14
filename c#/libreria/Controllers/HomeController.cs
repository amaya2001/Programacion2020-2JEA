using Microsoft.AspNetCore.Mvc;

namespace libreria.Controllers
{
    public class HomeController : Controller
    {
           public IActionResult Index()
        {
            return View();
        }

    }
}
