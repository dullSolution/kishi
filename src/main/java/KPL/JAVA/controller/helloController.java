package KPL.JAVA.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.ModelAndView;

import KPL.JAVA.mapper.StudentMapper;
import KPL.JAVA.service.StudentService;

//@RequestMapping(value = "/hello")
@Controller
public class helloController {

	@Autowired
	private StudentService service;
	
	@RequestMapping("/world")
	public String showMessage(HttpServletRequest request, HttpServletResponse response) {
//		request.setAttribute("msg", "youxi");
//		return "/WEB-INF/views/hello.html";
		return "/views/display";
	}

	@RequestMapping("/about")
	public String showCompany() {
//		System.out.println("/about");
		return "forward:/img/New_Storm_signature_7.png";
	}
	
	@RequestMapping("/Go2fill")
	public ModelAndView Goat2DB(HttpServletRequest request) {
//		request.setAttribute("msg", "back to login");


		
		ModelAndView view = new ModelAndView("/views/fillin");
//		view.addObject("welcome", "hello");
		return view;
	}
	
	@RequestMapping("/deleted2deleted")
	public String deleted2deleted() {
		service.deleted2deleted();
		return "forward:/";
	}
	
}
