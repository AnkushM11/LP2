# Define a dictionary of predefined responses
responses = {
    "hello": "Hi there! How can I assist you with your shopping today?",
    "products": "We have a wide range of products available. What are you looking for?",
    "options":"There are many options available for Mobile products some of them are as follows :1) Samsung 2) Apple 3) Oneplus 4) Xiomi 5) Oppo 6) Vivo 7) Motorola ",
    "samsung" : "Some of the latest options available in Samsung are 1) S23 Ultra 2) S23 3) Galaxy A50 4) Note10 5) Z-Flip 6)Galaxy Fold",
    "shipping":"We have free shipping for order above 500rs",
    "returns":"We have a return policy of 30 days from purchase date",
    "help": "I'm here to help! How can I assist you?",
    "bye": "Thank you for visiting! Have a great day!",
    "default": "I'm sorry, I didn't understand that. Could you please rephrase?",
}

# Define a function to handle user inputs and generate bot responses
def chatbot_response(user_input):
    # Convert user input to lowercase
    user_input = user_input.lower()
    
    # Check if user input matches any predefined responses
    if "hello" in user_input:
        return responses["hello"]
    elif "products" in user_input or "shop" in user_input:
        return responses["products"]
    elif "shipping" in user_input:
        return responses["shipping"]
    elif "return" in user_input:
        return responses["returns"]
    elif "help" in user_input:
        return responses["help"]
    elif "options" in user_input:
        return responses["options"]
    elif "samsung" in user_input:
        return responses["samsung"] 
    elif "bye" in user_input:
        return responses["bye"]
    else:
        return responses["default"]

# Main loop for user interaction
print("Chatbot: Hi, welcome to our online store! How can I assist you today?")

while True:
    user_input = input("User: ")
    response = chatbot_response(user_input)
    print("Chatbot: " + response)
    
    # Exit loop if user says "bye"
    if "bye" in user_input.lower():
        break