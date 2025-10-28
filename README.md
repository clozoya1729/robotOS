<p align="center">
  <img src="_assets/image/car.png" width="175">
</p>

# robotOS

[![Patreon](https://img.shields.io/badge/Support-Patreon-051D34?logo=patreon&logoColor=white)](https://www.patreon.com/lozoya)
[![Buy Me A Coffee](https://img.shields.io/badge/Donate-Buy%20Me%20A%20Coffee-FFDD00?logo=buymeacoffee&logoColor=white)](https://www.buymeacoffee.com/clozoya172b)
[![Ko-fi](https://img.shields.io/badge/Tip-Ko%E2%80%91fi-FF5E5B?logo=kofi&logoColor=white)](https://ko-fi.com/lozoya)
![License](https://img.shields.io/badge/license-AGPL--3.0-blue)

**Robot Operating System**

A lightweight embedded operating system in C for mobile and manipulator robots.  
This project focuses on a certifiable, real-time kernel and the platform services needed for perception, planning, and
control on resource-constrained controllers.

---

# Introduction

This project is designed as a generic, extensible operating system that provides a stable core while exposing clear
interfaces to hardware. The operating system defines the overall structure and common services, while the user supplies
the logic that connects those interfaces to specific devices.

A few complete examples are provided to show how typical hardware can be integrated, but the design ensures that modules
can be swapped out or extended without altering the core. Hardware differences are handled entirely through the
interface layer, keeping the system consistent and portable.

The goal is to create a framework-style operating system: stable at its core, adaptable at its boundaries, and capable
of interfacing with any hardware through well-defined extension points.

---

## 1. Scope

Start with one platform to iterate quickly; expand to multi-controller robots later.

- **Mobile Base (locomotion)**
    - **Drivetrain:** differential/omni/Mecanum, velocity/position control.
    - **Odometry:** wheel encoders, IMU fusion.
    - **Safety:** E-stop integration, watchdogs, speed limiting & geofencing.

- **Manipulator Arm**
    - **Kinematics:** FK/IK, limits & singularity handling.
    - **Control:** joint space position/velocity/torque; gravity compensation.
    - **Calibration:** homing, soft/hard limits, joint offset storage.

- **Perception**
    - **Sensors:** IMU, LiDAR, depth camera, 2D/3D localization.
    - **Mapping:** occupancy grid updates, loop-closure hooks (stub).
    - **Detection (optional):** fiducials/markers for alignment tasks.

- **Autonomy**
    - **Planning:** path & trajectory generation with constraints.
    - **State machine:** mode control (BOOT, IDLE, TELEOP, AUTO, ERROR).
    - **Teleop:** serial/Ethernet command bridge.

---

## 2. Architecture

All C, static configuration-first.

- **Bare-metal RTOS kernel**  
  Fixed-priority, deterministic schedule with tickless option.
- **Cyclic executive**  
  Time-triggered minor/major cycles for ultra-predictable loops.
- **MPU-guarded microkernel (optional)**  
  Memory regions per task on supported MCUs.
- **Middleware**  
  Minimal pub/sub, service calls, parameter server, and timebase.

---

## 3. Kernel Feature Set

- **Scheduling:** fixed-priority preemptive or cyclic; tickless timer.
- **Interrupts:** bounded latency ISRs; defer to tasks.
- **Sync:** priority-inheritance mutexes, event flags, queues, timers.
- **Memory:** static allocation only after init; optional MPU regions.
- **Timing:** monotonic timebase; micros/ms accessors.

---

## 4. Platform Services

### Communication

- UART/USB CDC, CAN/CAN-FD, SPI, I2C, Ethernet.
- Simple framed serial protocol; lightweight CAN/Ethernet stacks.

### Drivers

- **Motors/Servos/PWM**, **Encoders**, **IMU**, **LiDAR**, **Camera**, **GPIO**, **ADC/DAC**, **Flash/SD**, **Watchdog
  **, **Timers**.

### Middleware

- **Pub/Sub:** topic publish/subscribe for sensor & control streams.
- **Services:** request/response for configuration & commands.
- **Params:** key-value parameter store with NV journal.
- **Timebase:** µs/ms monotonic clock.

### Storage & Logging

- Flash/SD abstraction, journaling, event log (binary + text).

### Security (optional)

- Secure boot, image verification, crypto HAL.

---

## 5. Safety & Process

- **Coding Standard:** MISRA C:2012; deterministic control flow.
- **Static Analysis:** Cppcheck, PC-lint, Coverity (as available).
- **Timing Analysis:** WCET budgets for control & perception loops.
- **V&V:** unit tests, HIL with motor/encoder rigs, fail-safe testing.
- **Operational Safety:** E-stop path independent of user code; torque/speed limits.

---

## 6. Hardware Targets

- **MCUs:** STM32 (M4/M7/M33), NXP S32K, Renesas RA/RH, TI Sitara/AM-MCU.
- **Desired peripherals:** HW timers, multiple PWM, QEI encoders, CAN-FD, Ethernet MAC, DMA, MPU/ECC.

---

## 7. Deliverables (Phased)

- **Phase 0 — Board Bring-up**  
  Clock tree, startup.s, linker, UART console, GPIO, timers.
- **Phase 1 — Kernel**  
  Scheduler, tasks, mutex/events/queues, timers, ISR glue.
- **Phase 2 — Drivers**  
  PWM/motor, encoders, IMU, LiDAR, camera; DMA paths where useful.
- **Phase 3 — Middleware & Storage**  
  Pub/sub, services, params; FS + NV journal; logging.
- **Phase 4 — Control & Perception**  
  PID/MPC stubs; EKF odometry; occupancy updates.
- **Phase 5 — Planning & Autonomy**  
  Path/trajectory; mode state machine; teleop bridge; safety hooks.

---

## 8. Toolchain & CI

- **Compiler:** Vendor toolchains or `arm-none-eabi-gcc`; warnings as errors.
- **Build:** Make or CMake; artifacts: ELF, map, size, unit-test reports.
- **CI:** static analysis, unit tests (Ceedling/Unity), coverage, HIL smoke tests.
- **Tracing/Logs:** binary logs with timestamps; minimal printf in hot paths.

---

## 9. Design Guidelines

- Keep ISR bodies tiny; move work to tasks via events/queues.
- No heap after init; fixed pools; bounds/CRC on external I/O.
- Deadline monitors for control loops; degrade to SAFE on overrun.
- Separate config tables from logic; deterministic start-up order.
- Always validate operator commands and network inputs.

---

## 10. First Milestone

- Kernel running with 1 kHz (fast), 100 Hz (medium), 10 Hz (slow) tasks.
- Motor PWM + encoder loop: close a simple PID on a single wheel.
- IMU + encoder fusion demo: publish odometry via pub/sub.
- Serial teleop: set target velocity; watchdog proves reset on stall.
- NV journal stores PID gains; survives power cycle.

---


# Acronym Glossary

|   Acronym | Definition                                      |
|----------:|-------------------------------------------------|
|   ADC/DAC | Analog-to-Digital / Digital-to-Analog Converter |
|       DMA | Direct Memory Access                            |
|       EKF | Extended Kalman Filter                          |
|       HIL | Hardware-in-the-Loop                            |
|       IMU | Inertial Measurement Unit                       |
| IRAM/DRAM | Internal/External RAM                           |
|       ISR | Interrupt Service Routine                       |
|       MPC | Model Predictive Control                        |
|       MPU | Memory Protection Unit                          |
|        NV | Non-Volatile storage                            |
|       PID | Proportional-Integral-Derivative                |
|       QEI | Quadrature Encoder Interface                    |
|      RTOS | Real-Time Operating System                      |
|      WCET | Worst-Case Execution Time                       |

---

# Project Structure

```text
robot-os-c/
├─ app/ # modes + periodic tasks
│ ├─ app_main.c
│ ├─ app_tasks.c/h
│ └─ app_modes.c/h
├─ rt/ # tiny RTOS kernel + config
│ ├─ kernel/
│ │ ├─ os_kernel.c/h
│ │ ├─ os_sched.c/h
│ │ ├─ os_task.c/h
│ │ ├─ os_mutex.c/h
│ │ ├─ os_event.c/h
│ │ ├─ os_queue.c/h
│ │ ├─ os_timer.c/h
│ │ └─ os_isr.c/h
│ └─ config/
│ ├─ os_config.h
│ ├─ board.h
│ ├─ toolchain.h
│ ├─ linker.ld
│ └─ startup.s
├─ platform/
│ ├─ bsp/ # bring-up
│ │ ├─ bsp_init.c/h
│ │ ├─ clocks.c/h
│ │ ├─ mpu.c/h
│ │ └─ interrupts.c/h
│ └─ drivers/ # HALs
│ ├─ uart.c/h can.c/h eth.c/h
│ ├─ spi.c/h i2c.c/h
│ ├─ pwm.c/h motor.c/h servo.c/h
│ ├─ encoder.c/h imu.c/h lidar.c/h camera.c/h
│ ├─ gpio.c/h adc.c/h dac.c/h
│ ├─ timer.c/h watchdog.c/h
├─ middleware/
│ ├─ pubsub.c/h
│ ├─ services.c/h
│ ├─ params.c/h
│ └─ timebase.c/h
├─ sensors/
│ ├─ imu_driver.c/h
│ ├─ encoder_driver.c/h
│ ├─ lidar_driver.c/h
│ └─ camera_driver.c/h
├─ perception/
│ ├─ localization/ (ekf.c/h)
│ └─ mapping/ (occupancy.c/h)
├─ kinematics/
│ ├─ forward.c/h
│ ├─ inverse.c/h
│ └─ dynamics.c/h
├─ planning/
│ ├─ path.c/h
│ └─ trajectory.c/h
├─ control/
│ ├─ pid.c/h
│ ├─ mpc.c/h
│ └─ state_machine.c/h
├─ comms/
│ ├─ serial_proto.c/h
│ ├─ can_stack.c/h
│ └─ eth_stack.c/h
├─ storage/
│ ├─ fs.c/h
│ ├─ nv_journal.c/h
│ └─ log.c/h
├─ security/
│ ├─ secure_boot.c/h
│ └─ crypto_hal.c/h
├─ tests/
│ ├─ unit/
│ └─ hil/
├─ tools/
│ └─ scripts/
├─ docs/
│ ├─ STRUCTURE.md
│ ├─ CODING.md
│ └─ SAFETY.md
├─ build/
└─ Makefile
```

---

## Support This Work

Open source engineering takes a lot of time and coffee. If you would like to directly support ongoing research, development, and maintenance of these tools, you can do so here:

[![Patreon](https://img.shields.io/badge/Support-Patreon-051D34?logo=patreon&logoColor=white)](https://www.patreon.com/lozoya)

[![Buy Me A Coffee](https://img.shields.io/badge/Donate-Buy%20Me%20A%20Coffee-FFDD00?logo=buymeacoffee&logoColor=white)](https://www.buymeacoffee.com/clozoya172b)

[![Ko-fi](https://img.shields.io/badge/Tip-Ko%E2%80%91fi-FF5E5B?logo=kofi&logoColor=white)](https://ko-fi.com/lozoya)

Your support helps keep the project healthy and moving forward.

---

## License

This project is licensed under the GNU Affero General Public License v3.0 (AGPL-3.0). Any modified version made available to users over a network must also be released under the AGPL-3.0. See the LICENSE file for full details.

![License](https://img.shields.io/badge/license-AGPL--3.0-blue)

---



