/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab10;

/**
 *
 * @author navee
 */
public class PayPal implements IPaymentProcessor {

    @Override
    public boolean ProcessPayment(float amount) {
        if (amount > 0) {
            System.out.println("Processing PayPal payment of amount $" + amount);
            return true;
        } else {
            System.out.println("Amount can not be less than 0");
            return false;
        }
    }
}
