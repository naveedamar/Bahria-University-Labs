/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class RentalContract {
    private Vehicle vehicle;
    
    String name, contactNumber;
    int rentalPeriod, totalCost;

    public RentalContract(String name, String Contact, int period, int cost) {
        this.name = name;
        this.contactNumber = Contact;
        this.rentalPeriod = period;
        this.totalCost = cost;
    }
    
    public void printCustomerDetails(){
        System.out.println("Name: " + name);
        System.out.println("Contact Number" + contactNumber);
        System.out.println("Rental Period: " + rentalPeriod);
        System.out.println("Total Cost: " + totalCost);
    } 
    
    
    
}
