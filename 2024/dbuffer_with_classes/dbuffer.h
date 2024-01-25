#ifndef DBUFFER_H
#define DBUFFER_H

#include <iostream>

/**
 * @file dbuffer.h
 * @brief This file contains the declaration of the dbuffer class.
 */

/**
 * @class dbuffer
 * @brief A class representing a dynamic buffer.
 *
 * The dbuffer class provides functionality to create and manage a dynamic buffer.
 * It allows the user to construct an empty buffer or initialize it with a specified size and value.
 * The buffer is deallocated and memory is freed when the object is destroyed.
 */
class dbuffer {
    unsigned int _size;
    int *_buffer;

public:
    /**
     * @brief Default constructor.
     *
     * Constructs an empty dbuffer object with a size of 0 and no buffer allocated.
     */
    dbuffer();

    /**
     * @brief Constructor with size and value parameters.
     *
     * Constructs a dbuffer object with the specified size and initializes all elements
     * with the given value.
     *
     * @param size The size of the buffer.
     * @param value The value to initialize the buffer elements with (default is 0).
     */
    dbuffer(unsigned int size, int value = 0);

    /**
     * @brief Copy constructor.
     *
     * Constructs a dbuffer object by copying the contents of another dbuffer object.
     *
     * @param other The dbuffer object to be copied.
     */
    dbuffer(const dbuffer &other);

    /**
     * @class dbuffer
     * @brief A class representing a dynamic buffer.
     *
     * This class provides functionality to manage a dynamic buffer.
     * It allows copying and assigning buffers using the assignment operator.
     */
    dbuffer& operator=(const dbuffer &other);

    /**
     * @brief Destructor.
     *
     * Deallocates the buffer and frees the memory.
     */
    ~dbuffer(void);

    /**
     * @brief Get the size of the dbuffer.
     * 
     * @return The size of the dbuffer as an unsigned integer.
     */
    unsigned int get_size() const;

    /**
     * @brief Retrieves the value at the specified index in the buffer.
     * 
     * @param index The index of the value to retrieve.
     * @return The value at the specified index.
     */
    int get_value(unsigned int index) const;

    /**
     * @brief Sets the value at the specified index in the buffer.
     * 
     * This function allows you to set the value of an element at a specific index in the buffer.
     * The index should be a valid position within the buffer.
     * 
     * @param index The index of the element to set.
     * @param value The value to set at the specified index.
     */
    void set_value(unsigned int index, int value);

    /**
     * @brief Returns a reference to the value at the specified index.
     * 
     * @param index The index of the value to be returned.
     * @return A reference to the value at the specified index.
     */
    int &value(unsigned int index);
    const int &value(unsigned int index) const;

    /**
     * @brief Overloaded subscript operator.
     * 
     * This operator allows accessing the element at the specified index in the dbuffer.
     * 
     * @param index The index of the element to access.
     * @return A reference to the element at the specified index.
     */
    int &operator[](unsigned int index);
    const int &operator[](unsigned int index) const;

    /**
     * @brief Prints the contents of the dbuffer.
     * 
     * This function prints the elements stored in the dbuffer to the standard output.
     */
    void print();

    friend std::ostream &operator<<(std::ostream &os, const dbuffer &db);

};

/**
 * @brief Overloaded insertion operator for dbuffer class.
 * 
 * This function allows the dbuffer object to be printed using the insertion operator (<<).
 * 
 * @param os The output stream to write to.
 * @param db The dbuffer object to be printed.
 * @return The output stream after printing the dbuffer object.
 */
std::ostream &operator<<(std::ostream &os, const dbuffer &db);

#endif