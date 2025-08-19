/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mid;

/**
 *
 * @author navee
 */
public class CorporateRentalContract extends RentalContract {

    double discount = 0.15;
    String companyName;

    public CorporateRentalContract(String name, String Contact, int period, int cost) {
        super(name, Contact, period, cost);
        cost *= discount;
    }
    public void printCustomerDetails(double discount){
        super.printCustomerDetails();
        System.out.println("Discount: " + discount);
    }
}
