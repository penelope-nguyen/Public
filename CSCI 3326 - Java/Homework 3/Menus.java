public class Menus {
	
	public static void displayMenu () {
		System.out.print("1. Log in\n"
			+ "2. Sign up\n"
			+ "3. Exit\n\n");
	}
	
	public static void displayWelcome(Member user) {
		System.out.print("1. Display inventory\n"
				+ "2. Sort cars\n"
				+ "3. Log out\n\n"
				+ "Please input your choice: ");
	}
	
	public static void displayAdmin() { 
		System.out.print("1. Display inventory \n"
				+ "2. Add Car \n"
				+ "3. Delete Car \n"
				+ "4. Update Car \n"
				+ "5. Display Users \n"
				+ "6. Add User \n"
				+ "7. Delete User \n"
				+ "8. Update User\n"
				+ "9. Logout\n\n");
	}
	
	public static void displaySort() { 
		System.out.print("1. Sort by VIN \n"
				+ "2. Sort by Brand \n"
				+ "3. Sort by Model \n"
				+ "4. Sort by Year \n"
				+ "5. Sort by Mileage \n"
				+ "6. Sort by Price \n"
				+ "7. Sort by Color \n\n");
	}
	
	public static void displayUpdateCar() { 
		System.out.print("1. Update brand \n"
				+ "2. Update model \n"
				+ "3. Update year \n"
				+ "4. Update mileage \n"
				+ "5. Update price \n"
				+ "6. Update color \n\n");
	}
	
	public static void displayUpdateUser() { 
		System.out.print("1. Update password \n"
				+ "2. Update first name \n"
				+ "3. Update last name \n"
				+ "4. Update e-mail \n\n");
	}
}