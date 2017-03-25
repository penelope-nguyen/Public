import java.io.FileNotFoundException;
import java.util.Scanner;

public class HW3_main { 
	
	public static void main (String [] args) throws FileNotFoundException { 
		Scanner in = new Scanner(System.in);
		int choice = 0;
		Customers members = new Customers("customers.txt");
		Inventory carInventory = new Inventory("inventory.txt");
	
		System.out.println("Welcome to Carmax!\n");
		
		do {
			
			Menus.displayMenu();
			System.out.print("Please input your choice: ");
			choice = in.nextInt();
			System.out.println();
			
			if (choice == 3) 
				break;
			
			else if (choice == 1) {
				System.out.print("Please input your user id: ");
				String username = in.next();
				System.out.print("Please input your password: ");
				String password = in.next();
				System.out.println("");

				if (username.equals("admin")) { 
					if (password.equals("adminpass")) { 
						System.out.println("Welcome back admin's_name!\n");
						do { 
							Menus.displayAdmin();

							System.out.print("Please input: ");
							int adminChoice = in.nextInt();
							System.out.println();

							if (adminChoice == 1) 
								carInventory.displayAll();
								
							else if (adminChoice == 2)  
								carInventory.add();
							
							else if (adminChoice == 3)  
								carInventory.delete();
							
							else if (adminChoice == 4)  
								carInventory.update();
							
							else if (adminChoice == 5) 
								members.displayAll();
							
							else if (adminChoice == 6) 
								members.adminAdd();
							
							else if (adminChoice == 7) 
								members.delete();
							
							else if (adminChoice == 8) 
								members.update();
							
							else if (adminChoice == 9) { 
								System.out.println("Logging out admin...\n");
								break;
							}
							
							else 
								System.out.println("Not a valid choice! Please try again. ");
							
						} while (true);
					}
					
					else { 
					System.out.println("Invalid name or password.\n");
					continue;
					}
					
				}
				
				else { 
					if(members.login(username, password)) {

						Member user = members.getMember(username);
						System.out.println("Welcome back " + user.fn + " " + user.ln + "!\n");

						int insideChoice = 0;
						do { 
							Menus.displayWelcome(user);
							insideChoice = in.nextInt();
							System.out.println();
							if (insideChoice == 1) 
								carInventory.displayAll();
								
							else if (insideChoice == 2)
								 carInventory.sort();
							
							else if (insideChoice == 3) {
								System.out.println("Logging out...Goodbye " + user.fn + " " + user.ln + "~\n");
								break;
							}

							else { 
								System.out.print("Not a valid choice. Please try again");
								continue;
							}
						} while (true);
					}
				}
			}
				
			else if (choice == 2) {
				members.add();
				System.out.println("Thank you for your sign up!\n");
				continue;
			}
			
			else
				System.out.println("Not a valid choice.");
			
		} while (true);
		
		System.out.println("Thank you for using Carmax! Goodbye~");
		
		carInventory.updateInventory("cars.txt");
		members.updateCustomers("customers.txt");
		
	}
	
}