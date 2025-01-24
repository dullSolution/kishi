package KPL.JAVA.domain;

import java.io.Serializable;

public class Student implements Serializable{

	
	private Integer id;
	
	private String name;
	
	private String sno;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSno() {
		return sno;
	}

	public void setSno(String sno) {
		this.sno = sno;
	}

	public Integer getId() {
		return id;
	}

	@Override
	public String toString() {
		return "Student [id=" + id + ", name=" + name + ", sno=" + sno + "]";
	}
}
