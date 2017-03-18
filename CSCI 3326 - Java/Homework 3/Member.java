
public class Member { 
	String id;
	String pw;
	String fn;
	String ln;
	String email;
	
	public Member() { 
		id = "-1";
		pw = "NULL";
		fn = "NULL";
		ln = "NULL"; 
		email = "NULL";
	}
	public void setID(String ID_num) { 
		id = ID_num;
	}
	
	public void setPW(String pass) { 
		pw = pass;
	}
	
	public void setFN(String first){
		fn = first;
	}
	
	public void setLN(String last) { 
		ln = last;
	}
	
	public void setEmail(String mail) { 
		email = mail;
	}
	
	public void print() { 
		System.out.printf("%-10s%-15s%-15s%-15s%-20s\n", id, pw, fn, ln, email);
	}
}