# Shop Project CLI (C++)

![License](https://img.shields.io/badge/license-MIT-blue.svg) 
![C++](https://img.shields.io/badge/language-C%2B%2B-orange.svg)
![CLI](https://img.shields.io/badge/interface-CLI-green.svg)

A command-line interface (CLI) application for managing a shop's inventory, customers, and orders. Built with C++, this project provides a simple yet powerful way to handle shop operations directly from the terminal.

---

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)
- [How It Works](#how-it-works)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## Features

- **Inventory Management:** Add, update, and delete products in the shop's inventory.
- **Customer Management:** Add, update, and delete customer records.
- **Order Management:** Create and manage customer orders.
- **Data Persistence:** Save and load data to/from text files.
- **User-Friendly CLI:** Intuitive commands and prompts for easy interaction.

---

## Installation

To set up the Shop Project CLI, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/M1keEm/Shop_Project_CLI.git
2. **Navigate to the project directory:**
   ```bash
   cd Shop_Project_CLI
3. **Compile the application:**
   - Ensure you have a C++ compiler installed (e.g., g++).
   - Compile the project using the following command:
   ```bash
   g++ main.cpp -o shop_cli

4. **Run the application:**
   ```bash
   ./shop_cli

---

## Usage

The Shop Project CLI provides a menu-driven interface for managing shop operations. Follow the on-screen prompts to perform actions such as adding products, managing customers, and creating orders.

**Example Workflow**
1. **Add a Product:**

  - Select the "Add Product" option from the menu.

  - Enter the product details (name, price, quantity).

2. **Add a Customer:**

  - Select the "Add Customer" option from the menu.

  - Enter the customer details (name, email, phone).

3. **Create an Order:**

  - Select the "Create Order" option from the menu.

  - Choose a customer and add products to the order.

4. **View Data:**

  - Use the "View Products," "View Customers," or "View Orders" options to see stored data.

---

## Commands

The CLI supports the following commands through its menu interface:

- **Add Product:** Add a new product to the inventory.

- **Update Product:** Update an existing product's details.

- **Delete Product:** Remove a product from the inventory.

- **Add Customer:** Add a new customer to the database.

- **Update Customer:** Update an existing customer's details.

- **Delete Customer:** Remove a customer from the database.

- **Create Order:** Create a new order for a customer.

- **View Products:** Display all products in the inventory.

- **View Customers:** Display all customers in the database.

- **View Orders:** Display all orders.

---

## How it works

**Data Storage**

- Products, Customers, and Orders are stored in text files (`products.txt`, `customers.txt`, `orders.txt`).

- Data is loaded from these files when the application starts and saved back when changes are made.

**Code Structure**

- `main.cpp`: The entry point of the application. Handles the main menu and user input.

- `ShopManager.cpp`: Contains the core logic for managing products, customers, and orders.

- `FileHandler.cpp`: Provides utility functions for loading and saving data.

**Workflow**

- The user interacts with the CLI through a series of menus and prompts.

- Data is validated and processed before being saved to the appropriate text file.

- The application ensures data consistency and provides feedback for user actions.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeatureName`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeatureName`).
5. Open a pull request.

Please ensure your code follows the existing style and includes appropriate documentation.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contact

If you have any questions or suggestions, feel free to reach out:

- **MikeEm** - [My Github](https://github.com/m1keem)
- **Project Link** - [Repository](https://github.com/m1keem/shop_project_cli)
