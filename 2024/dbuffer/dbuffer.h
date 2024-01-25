#ifndef DBUFFER_H
#define DBUFFER_H

namespace dbuffer
{
    /**
     * @brief A struct representing a dynamic buffer.
     * 
     * This struct contains the size of the buffer and a pointer to the buffer.
     */
    struct dynamic_buffer
    {
        unsigned int size; ///< The size of the buffer.
        int *buffer; ///< A pointer to the buffer.
    };

    /**
     * @brief Prints the contents of the dynamic buffer.
     * 
     * @param db The dynamic buffer to be printed.
     */
    void print(const dynamic_buffer &db);

    /**
     * @brief Initializes the dynamic buffer.
     * 
     * @param db The dynamic buffer to be initialized.
     */
    void init(dynamic_buffer &db);

    /**
     * @brief Allocates memory for the dynamic buffer.
     * 
     * This function allocates memory for the dynamic buffer with the specified size.
     * If the size is not provided, the default size is set to 10.
     * 
     * @param db The dynamic buffer object.
     * @param size The size of the buffer to be allocated (default: 10).
     */
    void allocate(dynamic_buffer &db, unsigned int size = 10);

    /**
     * @brief Deallocates the memory used by the dynamic buffer.
     * 
     * This function frees the memory allocated for the dynamic buffer, releasing it back to the system.
     * 
     * @param db The dynamic buffer to deallocate.
     */
    void deallocate(dynamic_buffer &db);

    /**
     * @brief Sets the value of the dynamic buffer.
     * 
     * This function sets the value of the dynamic buffer to the specified value.
     * If no value is provided, the default value is 0.
     * 
     * @param db The dynamic buffer to set the value for.
     * @param value The value to set the dynamic buffer to (default is 0).
     */
    void set(dynamic_buffer &db, int value = 0);

    /**
     * @brief Copies the contents of the source dynamic_buffer to the destination dynamic_buffer.
     * 
     * This function copies the elements from the source dynamic_buffer to the destination dynamic_buffer.
     * The destination dynamic_buffer must have enough capacity to accommodate the copied elements.
     * 
     * @param src The source dynamic_buffer from which the elements will be copied.
     * @param dst The destination dynamic_buffer where the elements will be copied to.
     */
    void copy(const dynamic_buffer &src, dynamic_buffer &dst);

}

#endif