package KPL.JAVA.controller;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import KPL.JAVA.domain.Employee;
import KPL.JAVA.domain.Goat;
import KPL.JAVA.service.EmployeeService;

@Controller
public class EmployeeController {

	@Autowired
	private EmployeeService service;
	
	@RequestMapping("/showGoat")
	public String showAllGoat() {
		List<Goat> employeeList=null;
		
		employeeList=service.showALLEmployees();
		System.out.println(employeeList);
		return "/admin/hello";
	}
	
	@RequestMapping("/showTable")
	public ModelAndView showTable() {
		ModelAndView mv=new ModelAndView();
		List<Goat> employeeList=service.showALLEmployees();
		
		mv.addObject("list", employeeList);
		mv.setViewName("/views/show");
		
		return mv;
		
	}
	
	@RequestMapping("/select")
	public ModelAndView selectOneEmployee(String name
//			HttpServletRequest request
			) {
		ModelAndView mv=new ModelAndView();
		List<Goat> employeeList=service.selectOneEmployee(name);
//		System.out.println(employeeList);
		mv.addObject("list", employeeList);
		mv.setViewName("/views/show");
		
		return mv;
		
	}
	
	@RequestMapping("/Goat2DB")
	public String Goat2DB(HttpServletRequest request) {
		String name=(String)request.getParameter("name");
		String department=(String)request.getParameter("department");
		String shu=(String)request.getParameter("goat");
//		System.out.println(name+department+shu);
		int goat=Integer.parseInt(shu);
		if(service.insertOneGoat(name, goat, department)) {
			request.setAttribute("message", "success");
			
		}else
			request.setAttribute("message", "fail");
		return "forward:/";
	}
}
