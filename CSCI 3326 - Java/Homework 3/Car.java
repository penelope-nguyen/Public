import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedHashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Car { 
	
	String vin;
	String brand;
	String model;
	int year;
	int mileage;
	double price;
	char color;
	
	public void setVin(String v) {
		vin = v;
	}
	
	public void setBrand(String b) { 
		brand = b;
	}
	
	public void setModel(String m) { 
		model = m;
	}
	
	public void setYear(int y) { 
		year = y;
	}
	
	public void setMileage(int m) { 
		mileage = m;
	}
	
	public void setPrice(double p) { 
		price = p;
	}
	
	public void setColor(char c) { 
		color = c;
	}
	
	public void print() { 
		System.out.printf("%-13s%-12s%-10s%-10s%-10s%-10.2f%-10s\n", vin, brand, model, year, mileage, price, color);
	}
	
	public static LinkedHashMap readCars(String fname) throws FileNotFoundException { 
		LinkedHashMap list = new LinkedHashMap ();
		System.out.println(fname);
		File file = new File(fname);
		Scanner f1 = new Scanner(file);
		while(f1.hasNext()) { 
			Car newCar = new Car();
			StringTokenizer str = new StringTokenizer(f1.nextLine(), "/");
			newCar.setVin(str.nextToken());
			newCar.setBrand(str.nextToken());
			newCar.setModel(str.nextToken());

			newCar.setYear(Integer.parseInt(str.nextToken()));
			newCar.setMileage(Integer.parseInt(str.nextToken()));
			newCar.setPrice(Double.parseDouble(str.nextToken()));
			newCar.setColor(str.nextToken().charAt(0));

			newCar.print();
			list.put(newCar.vin, newCar);
		}
		f1.close();
		return list;
	}
	
}