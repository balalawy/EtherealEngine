#ifndef MML_JOYSTICKIMPLLINUX_HPP
#define MML_JOYSTICKIMPLLINUX_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <linux/input.h>


namespace mml
{
namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Linux implementation of joysticks
///
////////////////////////////////////////////////////////////
class joystick_impl
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ////////////////////////////////////////////////////////////
    joystick_impl();

    ////////////////////////////////////////////////////////////
    /// \brief Perform the global initialization of the joystick module
    ///
    ////////////////////////////////////////////////////////////
    static void initialize();

    ////////////////////////////////////////////////////////////
    /// \brief Perform the global cleanup of the joystick module
    ///
    ////////////////////////////////////////////////////////////
    static void cleanup();

    ////////////////////////////////////////////////////////////
    /// \brief Check if a joystick is currently connected
    ///
    /// \param index Index of the joystick to check
    ///
    /// \return True if the joystick is connected, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    static bool is_connected(unsigned int index);

    ////////////////////////////////////////////////////////////
    /// \brief Open the joystick
    ///
    /// \param index Index assigned to the joystick
    ///
    /// \return True on success, false on failure
    ///
    ////////////////////////////////////////////////////////////
    bool open(unsigned int index);

    ////////////////////////////////////////////////////////////
    /// \brief Close the joystick
    ///
    ////////////////////////////////////////////////////////////
    void close();

    ////////////////////////////////////////////////////////////
    /// \brief Get the joystick capabilities
    ///
    /// \return joystick capabilities
    ///
    ////////////////////////////////////////////////////////////
    joystick_caps get_capabilities() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the joystick identification
    ///
    /// \return joystick identification
    ///
    ////////////////////////////////////////////////////////////
    joystick::identification get_identification() const;

    ////////////////////////////////////////////////////////////
    /// \brief Update the joystick and get its new state
    ///
    /// \return joystick state
    ///
    ////////////////////////////////////////////////////////////
    joystick_state update();

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    int                          _file;                 ///< File descriptor of the joystick
    char                         _mapping[ABS_MAX + 1]; ///< Axes mapping (index to axis id)
    joystick_state                _state;                ///< Current state of the joystick
    mml::joystick::identification _identification;       ///< identification of the joystick
};

} // namespace priv

} // namespace mml


#endif // MML_JOYSTICKIMPLLINUX_HPP