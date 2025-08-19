/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.finals;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author navee
 */
class Order {
    private List<MEAL> mealsInOrder;
    private double totalCost;

    public Order() {
        this.mealsInOrder = new ArrayList<>();
        this.totalCost = 0.0;
    }

    public void addMeal(MEAL meal) {
        mealsInOrder.add(meal);
        totalCost += meal.getPrice();
        System.out.println("Added: " + meal.getName() + " (" + meal.getDetails() + ")");
    }

    public void showOrderSummary() {
        System.out.println("\n--- Your Order ---");
        for (MEAL meal : mealsInOrder) {
            System.out.printf("Name: " + meal.getName() + " Details: " + meal.getDetails() + "Price: "+  meal.getPrice());
        }
        System.out.printf("------------------%nTotal: " + totalCost);
    }

    public void startPreparing() {
        System.out.println("\n--- Now Preparing Your Order ---");
        for (MEAL meal : mealsInOrder) {
            meal.prepare();
        }
        System.out.println("All your food is being prepared!");
    }
}