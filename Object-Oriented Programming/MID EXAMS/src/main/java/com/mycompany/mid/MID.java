/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class MID {

    public static void main(String[] args) {
        System.out.println("MID");
        System.out.println("");
        
        Car carOne = new Car(2000, 1000, "BMW", "SS", true);
        carOne.displayDetails(2);
        System.out.println("");

        Truck truckOne = new Truck(1990, 500, "Toyota", "E", true);
        truckOne.displayDetails(300);
        System.out.println("");
        
        HeavyTruck heavyOne = new HeavyTruck(1964, 100, "Szew", "T", true);
        heavyOne.displayDetails(500);
        System.out.println("");
        
        RentalContract renterOne = new RentalContract("Naveed", "232134", 6, 100);
        renterOne.printCustomerDetails();
        System.out.println("");
        
        CorporateRentalContract corpOne = new CorporateRentalContract("IBM", "932144", 3, 500);
        corpOne.printCustomerDetails();
        corpOne.printCustomerDetails(.20);

    }
}
