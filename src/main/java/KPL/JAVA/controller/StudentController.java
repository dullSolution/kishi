package KPL.JAVA.controller;

import java.net.http.HttpRequest;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import KPL.JAVA.domain.Student;
import KPL.JAVA.service.StudentService;

@Controller
public class StudentController {

	@Autowired
	private StudentService service;
	
	@RequestMapping("/login")
	public String login(Student student,HttpServletRequest request) {
		try {
			Student s =service.login(student);
			if(s!=null) {
				request.getSession().setAttribute("user_session", s);
				return "redirect:/admin/main.jsp";
			}
			request.setAttribute("msg", "账号密码错误");
			return "forward:/admin/login.jsp";
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			request.setAttribute("msg", "系统错误");
			return "forward:/admin/login.jsp";
		}
		
	}
	
//	@RequestMapping("/ok")
//	public String ok() {
//		
//		List<Student> s=service.show();
//		System.out.println(s);
//		return "/admin/hello";
//	}
//	
	

}
