"""
Applying for Stanford Code in Place 06 as a section leader and using this script to create demo teaching video for the role.

Problem statement:
Convert weight on Earth to equivalent weight on Mars

take an input from the user
do conversion
give the results back

37.8% of the weight on Earth
37.8 *100 = 0.378
"""

MAR_WEIGHT = 0.378  # float


def main():
    # stores the input result, the input function returns a string Naveed is a string
    user_weight = float(input("Enter weight: "))

    # converting the weight to mar weight
    converted_weight = user_weight * MAR_WEIGHT

    print("Your weight on Mars is: " + str(converted_weight))


if __name__ == "__main__":
    main()
