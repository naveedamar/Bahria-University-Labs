/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.finals;

/**
 *
 * @author navee
 */
class MexicanMeal extends AbstractMeal {
    private String filling;

    public MexicanMeal(String dishType, String filling) {
        super(dishType, (dishType.equalsIgnoreCase("Burritos") ? 13.0 : 10.0));
        this.filling = filling;
        System.out.println(" Mexican Meal: " + getDetails() + " ready.");
    }
    
    @Override
    public void prepare() {
        super.prepare();
        System.out.println("Making " + getName() + " with " + filling + " filling (Mexican style).");
    }

    @Override
    public String getDetails() { return getName() + " with " + filling + " filling"; }
}
