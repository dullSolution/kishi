package KPL.JAVA.domain;

public class Goat {

	
	private String name;
	
	private int goat;
	
	private Integer id;
	
	private int uid;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getGoat() {
		return goat;
	}

	public void setGoat(int goat) {
		this.goat = goat;
	}

	public Integer getId() {
		return id;
	}

	public int getUid() {
		return uid;
	}

	public Goat(String name, int goat) {
		super();
		this.name = name;
		this.goat = goat;
	}

	@Override
	public String toString() {
		return "Goat [name=" + name + ", goat=" + goat + "]";
	}
	
	
}
