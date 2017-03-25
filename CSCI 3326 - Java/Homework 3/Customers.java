import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;
public class Customers { 
	
	HashMap members;
	
	public Customers(String fname) throws FileNotFoundException { 
		members = readCustomers(fname);
	}
	
	public void add() { 
		
		Scanner in = new Scanner(System.in);
	
		Member newMember = new Member();
		
		System.out.print("Please input user id: ");
		newMember.setID(in.next());
		
		System.out.print("Please input password: ");
		newMember.setPW(in.next());

		System.out.print("Please input your first name: ");
		newMember.setFN(in.next());

		System.out.print("Please input your last name: ");
		newMember.setLN(in.next());

		System.out.print("Please input your e-mail: ");
		newMember.setEmail(in.next());
		System.out.println();
		
		members.put(newMember.id, newMember);
		
		printWithCat(newMember);
		
	}
	
	public void updateCustomers(String fname) throws FileNotFoundException { 
		
		PrintWriter outputFile = new PrintWriter(fname);
		for (Object ID: members.keySet()) { 
			Member member = (Member) members.get(ID);
			outputFile.println(member.id + "/" + member.pw + "/" + member.fn + "/" + member.ln + "/" + member.email);
		}
		outputFile.close();
	}
	
	public void adminAdd() { 
		add();
		System.out.println("User has succesfully been added.\n");
		displayAll();
	}

	public boolean login(String ID, String pass) {
		
		Member login = (Member)members.get(ID);
		if (login == null) 
			System.out.println("User does not exist.\n");
		else  {
			String login_pass = login.pw;
			if (login_pass.equals(pass))
				return true;
			else 
				System.out.println("Invalid username or password. ");
		}
		return false;
		
	}
	
	public Member getMember(String ID) {
		
		return (Member)members.get(ID);
		
	}
	
	public static HashMap readCustomers(String fname) throws FileNotFoundException { 
		
		HashMap list = new HashMap();
		File file = new File(fname);
		Scanner f1 = new Scanner(file);
		
		while(f1.hasNext()) { 
			Member newMember = new Member();
			StringTokenizer str = new StringTokenizer(f1.nextLine(), "/");
			newMember.setID(str.nextToken());
			newMember.setPW(str.nextToken());
			newMember.setLN(str.nextToken());
			newMember.setFN(str.nextToken());
			newMember.setEmail(str.nextToken());
			list.put(newMember.id, newMember);
		}
		
		f1.close();
		return list;
	
	}
	
	public void displayAll() { 
		
		printCategories();
		for (Object username: members.keySet()) { 
			Member user = (Member) members.get(username);
			user.print();
		}
		System.out.println();
	
	}
	
	public void printCategories() { 
	
		System.out.printf("%-10s%-15s%-15s%-15s%-20s\n", "ID", "Password", "First Name", "Last Name", "E-mail");
	
	}
	
	public void printWithCat(Member member) { 
		
		printCategories();
		member.print();
		System.out.println();
		
	}
	
	public void delete() { 
		
		Scanner in = new Scanner(System.in);
		displayAll();
		System.out.print("Please input ID: ");
		String username = in.next();
		System.out.println();
		if (members.containsKey(username)) { 
			Member toDelete = (Member) members.get(username);
			printWithCat(toDelete);
			members.remove(username);
			System.out.println("This user has been sucessfully deleted.\n");
			displayAll();
		}
		else 
			System.out.println("User does not exist.\n");
	}
	

	public void update() {
		
		Scanner in = new Scanner(System.in);
		
		displayAll();
		
		System.out.print("Please input ID: ");
		String username = in.next();
		System.out.println();
		
		if (members.containsKey(username)) { 
			Menus.displayUpdateUser();
			Member member = (Member) members.get(username);
			
			System.out.print("Please select option: ");
			int choice = in.nextInt();
			
			if (choice == 1) {
				System.out.print("Please input new password: ");
				member.setPW(in.next());
			}
			
			else if (choice == 2) {
				System.out.print("Please input new first name: ");
				member.setFN(in.next());
			}
			
			else if (choice == 3) {
				System.out.print("Please input new last name: ");

				member.setLN(in.next());
			}
			
			else if (choice == 4) {
				System.out.print("Please input new e-mail: ");
				member.setEmail(in.next());
			}			
			
			else {
				System.out.println("\nOption is not valid.\n" );
				return;
			}
			
			members.put(member.id, member);
			System.out.println("\nIt's been updated. Thank you. \n");
			printWithCat(member);
			
		}
		
		else 
			System.out.println("User does not exist.\n");
		
	}
}