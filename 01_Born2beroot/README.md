![Screaming Root](https://tenor.com/en-GB/view/ron-weasley-harry-potter-mandrake-scream-piercing-gif-5055272.gif)

# Born2beroot

## Introduction

*This project aims to introduce you to the wonderful world of virtualization.*

You will create your first machine in VirtualBox (or UTM if you can’t use VirtualBox)
under specific instructions. Then, at the end of this project, you will be able to set up
your own operating system while implementing strict rules.

Grade: 125 / 100

![grade](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/grade.jpg)

Please see [subject](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/subject.pdf) for more details on this project.

**Disclaimer:** This is a list of very *loose* concepts that I studied while investigating for this project. Not organized in any way, and it might only be useful if you are a complete beginner. Please refer to INDEX to see all contents. There is also a Bibliography at the end with all (mostly) the places where I got this info.

If this was useful to you, please do not forget to leave me a :star:

<br>

----
<br>

## INDEX

<br>

- [Loose Concepts](#loose-concepts)
- [List of useful commands](#list-of-useful-commands) 
- [Questions I was asked when evaluating the project](#questions-i-was-asked-when-evaluating-the-project)
- [Bibliography](#bibliography)

<br>

----
<br>

## Loose Concepts

<br>

**Virtual Machine:** A virtual machine (VM) is a digital version of a physical computer. Virtual machine software can run programs and operating systems, store data, connect to networks, and do other computing functions, and requires maintenance such as updates and system monitoring.
Virtual Machines are extremely flexible - you can tell them how many processes they can run, how much RAM they can use, etc etc etc. They are specially usefull for developers as you can emulate any OS you wish to in order to code specifically for that environment. Plus, if you do anything wrong when using a VM, you can just delete it and start over, if you want to test anything that you are not sure of, you can take a snapshot of the maching at that state, and proceed from there, going back anytime you wish to do so, among other possibilities. Virtual Machines are completely isolated, they are not "aware" of what they are. If a VM is hacked, for example, the main OS might not even notice it.
In order to create a Virtual Machine, you need an Hypervisor - this is something like Oracle, or VirtualBox. This is responsible for creating a virtual CPU, RAM, storage, using only the resources available from your main machine.
There are Type 1 and 2 Hypervisors: A type 2 HV uses an OS, and then a software like the one we use on 42. Type 1 is installed directly on the hardware.

**Kernel:** The kernel is a computer program at the core of a computer's operating system and generally has complete control over everything in the system. It is the portion of the operating system code that is always resident in memory and facilitates interactions between hardware and software components. A full kernel controls all hardware resources (e.g. I/O, memory, cryptography) via device drivers, arbitrates conflicts between processes concerning such resources, and optimizes the utilization of common resources e.g. CPU & cache usage, file systems, and network sockets. On most systems, the kernel is one of the first programs loaded on startup (after the bootloader). It handles the rest of startup as well as memory, peripherals, and input/output (I/O) requests from software, translating them into data-processing instructions for the central processing unit. The kernel functions since the computer is turned on, until it is turned off, and it might be considered the most important part of the OS.

![kernel](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/kernel.png)

**Linux kernel:** The Linux kernel is a free and open-source, monolithic, modular, multitasking, Unix-like operating system kernel. It was originally authored in 1991 by Linus Torvalds for his i386-based PC, and it was soon adopted as the kernel for the GNU operating system, which was written to be a free (libre) replacement for Unix.
A common missconception is that Linux is an OS, but it is only a kernel. GNU, an OS, was often combined with LINUX, as it was also free. This popular combination (LINUX + GNU) was often called just 'Linux', which caused the idea that Linux is an OS.

**UNIX:** Unix is a family of multitasking, multiuser computer operating systems that derive from the original AT&T Unix, whose development started in 1969 at the Bell Labs research center by Ken Thompson, Dennis Ritchie, and others.
The most popular version of UNIX used today is MacOS.

![unix](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/unix.png)

**GUI:** The GUI, graphical user interface, is a form of user interface that allows users to interact with electronic devices through graphical icons and audio indicator such as primary notation, instead of text-based UIs, typed command labels or text navigation. GUIs were introduced in reaction to the perceived steep learning curve of CLIs (command-line interfaces), which require commands to be typed on a computer keyboard.

**Distro:** A Linux distribution (often abbreviated as distro) is an operating system made from a software collection that includes the Linux kernel and, often, a package management system. Linux users usually obtain their operating system by downloading one of the Linux distributions, which are available for a wide variety of systems ranging from embedded devices (for example, OpenWrt) and personal computers (for example, Linux Mint) to powerful supercomputers (for example, Rocks Cluster Distribution).

A typical Linux distribution comprises a Linux kernel, GNU tools and libraries, additional software, documentation, a window system (the most common being the X Window System, or, more recently, Wayland), a window manager, and a desktop environment.

![distros](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/distros.png)

There are four main branches when it comes to Linux distros:

![debian](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/debian.png)

**The Debian Branch**
    - Easiest to start if you are a complete beginer;
    - Most of Debian distros are based on UBUNTO, the most popular, most of commands and operations are the same as in UBUNTO, you just have like different "skins", like Kubunto or LinuxMint;
    - Most of them use apt as a package manager. If you see an apt command, you are most likely in a Debian based distro.

![suse](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/suse.png)

**The Suse Branch**
    - One of the first distros of Linux;
    - The SUSE Linux Enterprise Server (SLES) is designed for use in mainframes, servers, and workstations.

![redhat](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/redhat.png)

**The RedHat Branch**
    - Fedora, the distro used by Linus Torvalds, is part of this branch.
    - Very solid, high level of security, preformance focoused;

![arch](https://github.com/peterbikes/42-School-Common-Core/blob/main/01_Born2beroot/extra/arch.png)

**Arch Linux | Gentoo Branch**
    - For advanced users, very community driven;
    - Very modular, you have to install pretty much everything.

Think of Linux distros like cars: there are trucks, smart cars, f1's. They are based on the same principle, but they all serve different needs.

**LSBLK:** *(list block devices)* Lsblk is used to display details about block devices and these block devices (except ram disk) are basically those files that represent devices connected to the pc. It queries /sys virtual file system and udev db to obtain information that it displays. And it basically displays output in a tree-like structure. This command comes pre-installed with the util-Linux package.

![lsblk](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/lsblk)

It provides the following information:

    - Name of the device;
    - MAJ MIN indicates the names with which the kernel refers internally to devices. The first number identifies to the kernel the device driver it must use to communicate with the device. The minor number identifies the specific device among all those using the same device driver.
    - RM, for wether or not they are removable (0 for no, 1 for yes);
    - RO, meaning if they are or not 'read-only' (0 for no, 1 for yes);
    - Type of the device;
    - Mount point to the file system.

**LVM:** Logical volume management (LVM) is a form of storage virtualization that offers system administrators a more flexible approach to managing disk storage space than traditional partitioning. This type of virtualization tool is located within the device-driver stack on the operating system. It works by chunking the physical volumes (PVs) into physical extents (PEs). The PEs are mapped onto logical extents (LEs) which are then pooled into volume groups (VGs). These groups are linked together into logical volumes (LVs) that act as virtual disk partitions and that can be managed as such by using LVM.
PV (physical volumes like disks) compose the VG (volume group), that can be divided in Logical Volumes.

**Debian:** Debian, also known as Debian GNU/Linux, is a Linux distribution composed of free and open-source software, developed by the community-supported Debian Project, which was established by Ian Murdock on August 16, 1993. The first version of Debian (0.01) was released on September 15, 1993, and its first stable version (1.1) was released on June 17, 1996. The Debian Stable branch is the most popular edition for personal computers and servers. Debian is also the basis for many other distributions, most notably Ubuntu.

**CentOS:** CentOS (from Community Enterprise Operating System; also known as CentOS Linux) is a Linux distribution that provides a free and open-source community-supported computing platform, functionally compatible with its upstream source, Red Hat Enterprise Linux (RHEL). In January 2014, CentOS announced the official joining with Red Hat while staying independent from RHEL, under a new CentOS governing board.

**Rocky Linux:** Rocky Linux is a Linux distribution developed by Rocky Enterprise Software Foundation, which is a privately owned benefit corporation that describes itself as a "self imposed not-for-profit". It is intended to be a downstream, complete binary-compatible release using the Red Hat Enterprise Linux (RHEL) operating system source code. The project's aim is to provide a community-supported, production-grade enterprise operating system. Rocky Linux, along with Red Hat Enterprise Linux and SUSE Linux Enterprise, has become popular for enterprise operating system use.

**KDUMP:** Kdump is a feature of the Linux kernel that creates crash dumps in the event of a kernel crash. When triggered, kdump exports a memory image (also known as vmcore) that can be analyzed for the purposes of debugging and determining the cause of a crash. The dumped image of main memory, exported as an Executable and Linkable Format (ELF) object, can be accessed either directly through /proc/vmcore during the handling of a kernel crash, or it can be automatically saved to a locally accessible file system, to a raw device, or to a remote system accessible over network.

**SELinux:** SELinux is a security enhancement to Linux which allows users and administrators more control over access control.
Access can be constrained on such variables as which users and applications can access which resources. These resources may take the form of files. Standard Linux access controls, such as file modes (-rwxr-xr-x) are modifiable by the user and the applications which the user runs. Conversely, SELinux access controls are determined by a policy loaded on the system which may not be changed by careless users or misbehaving applications. SELinux also adds finer granularity to access controls. Instead of only being able to specify who can read, write or execute a file, for example, SELinux lets you specify who can unlink, append only, move a file and so on. SELinux allows you to specify access to many resources other than files as well, such as network resources and interprocess communication (IPC).

**AppArmor:** AppArmor is an effective and easy-to-use Linux application security system. AppArmor proactively protects the operating system and applications from external or internal threats, even zero-day attacks, by enforcing good behavior and preventing both known and unknown application flaws from being exploited. AppArmor supplements the traditional Unix discretionary access control (DAC) model by providing mandatory access control (MAC). It has been included in the mainline Linux kernel since version 2.6.36 and its development has been supported by Canonical since 2009.

**Aptitude | Apt:**

First, what is a 'package'?

Most software applications designed for Linux or Unix systems are distributed as packages, which are archives that contain the pre-compiled binary software files, installation scripts, configuration files, dependency requirements, and other details about the software. These packages are typically specific to a particular distribution and formatted in that distribution’s preferred package format, such as .deb for Debian/Ubuntu and .rpm for CentOS/RHEL.

Its very common in almost any operating system for software to require other software to run. In Linux, each package contains metadata detailing the additional packages that are required. These additional packages are called dependencies. A single package can sometimes have hundreds of dependencies. When installing, upgrading, or removing packages, these dependencies may also need to installed, upgraded, and optionally removed.

A package manager reduces the complexity for the end-user by automating the process of obtaining, installing, upgrading, and removing packages and their dependencies. This dramatically improves the user experience and the ability to properly and efficiently manage the software on your Linux system. Today, package managers can be a defining feature for Linux distributions and many system administrators prefer to use a particular distribution based on its package management system (among other considerations).

APT and Aptitude are package managers.

What is APT?

APT stands for Advanced Packaging Tool. It is an open-source tool, which means you can use it without the need to pay anything. APT is designed to handle software installation and removal. APT was part of Debian’s .deb package; however, it was updated to work with the RPM Package Manager.
If you have used APT before, you would have noticed that it is a command-line tool. This means you need to use commands to work with it with no visual reference from a graphical interface (the initial plan was to include a graphical interface, but the idea was later dropped). To use it, you need to provide the package name. The package should have its sources specified in the ‘/etc/apt/sources.list.’ It should also contain all the dependencies list that the package needs to install automatically. If you use the apt command, it will not only download and install the required dependencies for the said package. As a user, you do not have to worry about the package dependencies.
The approach taken by APT is flexible. This means that the user can configure how APT works, including adding new sources, providing up-gradation options, and so on!
With time, APT showed improvements on how it can be handled. Also, Debian developers are in full control of how it gets updated.

What is Aptitude?

Aptitude is also an advanced packaging tool. However, it is a front-end tool that gives users access to the user-interface to access functionality. This means that you can use Aptitude to install and remove packages using it. Debian created aptitude. But, with time, they released it for other RPM-based distributions.

***Difference between APT and Aptitude***

Now that we have a good understanding of what APT and Aptitude has to offer, it is now time to learn about their difference. Let’s get started.
The first difference you will notice is that APT is a lower-level package manager, and Aptitude is a high-level package manager. This means that APT can be used in other higher-level package managers.
Another big difference is the functionality offered by both of the tools. Aptitude offers better functionality compared to apt-get. In fact, it contains the functionalities of apt-get, apt-mark, and apt-cache.
For instance, apt-get can be used effectively for package up-gradation, installation, resolving dependencies, system up-gradation, and so on. However, Aptitude offers more features thanks to the inclusion of functionalities of apt-cache and apt-mark. This means Aptitude can be used for more functionality, including package search, setting package installation as automation or manual, and more refined actions on the packages.
If you have been following closely, you by now know that Aptitude comes with an interactive UI in addition to that of the text-only. APT, on the other hand, lacks UI. This is because of the nature of apt-get as it is a low-level package manager and hence restricted to the command-line interface. As Aptitude is a high-level tool, it offers both an interactive interface along with the command-line operation.
In short, Aptitude has more features and hence can be termed as a better package management tool compared to that of apt-get.

**SSH Service:** SSH or Secure Shell is a network communication protocol that enables two computers to communicate and share data. An inherent feature of ssh is that the communication between the two computers is encrypted meaning that it is suitable for use on insecure networks. SSH is often used to "login" and perform operations on remote computers but it may also be used for transferring data.

**UFW:** *(Uncomplicated Firewall)* One of the many heralded aspects of Linux is its security. From the desktop to the server, you’ll find every tool you need to keep those machines locked down as tightly as possible. For the longest time, the security of Linux was in the hands of iptables (which works with the underlying netfilter system). Although incredibly powerful, iptables is complicated — especially for newer users. To truly make the most out of that system, it may take weeks or months to get up to speed. Thankfully, a much simpler front end for iptables is ready to help get your system as secure as you need. That front end is Uncomplicated Firewall (UFW). UFW provides a much more user-friendly framework for managing netfilter and a command-line interface for working with the firewall. On top of that, if you’d rather not deal with the command line, UFW has a few GUI tools that make working with the system incredibly simple.

**SUDO:** Sudo stands for SuperUser (Switch User?) DO and is used to access restricted files and operations. By default, Linux restricts access to certain parts of the system preventing sensitive files from being compromised. The sudo command temporarily elevates privileges allowing users to complete sensitive tasks without logging in as the root user.

**TTY:** *(teletype)* Linux operating system represents everything in a file system. The hardware devices that we attach are also represented as a file. The terminal is also represented as a file. The tty command displays information related to terminal. The tty command of terminal basically prints the file name of the terminal connected to standard input. TTY is short of teletype, but popularly known as a terminal. It allows you to interact with the system by passing on data (your input) to the system, and displaying the output produced by the system.

**Difference Between Static and Dynamic Memory Allocation:** Dynamic memory allocation refers to memory allocation that occurs during the execution or runtime of a program. Static memory refers to memory allocation that occurs during the compilation process.

![memory_allocation](https://github.com/peterbikes/42-School-Common-Core/tree/main/01_Born2beRoot/extra/memory_allocation.png)

## List of useful commands

- **'su'** : switch to root (you should not need this during the defense);

- **'sudo -V'** : show sudo version;

- **'sudo visudo'** : edit the sudoers file;

- **'sudo -v'** : extends the sudo timeout for another 5 minutes;

- **'sudo -k'** : invalidates the user's timestamp, the next time sudo is run a password will be required;

- **'sudo adduser \<newuser\>'** : creates a new user;

- **'sudo addgroup \<newgroup\>'** : creates a new group;

- **'sudo adduser \<newuser\> \<groupname\>'** : adds user to group;

- **'sudo deluser \<username\>'** : - removes user;

- **'sudo deluser \<username\> \<groupname\>'** : removes user from group;

- **'sudo chage -l \<username\>'** : show user's password aging information;

- **'getent passwd'** : show all users accounts;

- **'getent group'** : show all groups;

- **'getent passwd \<username\>'** : get details for a particular user;

- **'getent group \<groupname\>'** : - displays information about that group, including all user members;

- **'sudo ufw status'**: displays ufw status and port rules;

- **'sudo ufw allow \<port number\>'** : allows \<port number\> to pass UFW;

- **'sudo ufw delete allow \<port number\>'** : blocks \<port number\> from passing UFW;

- **'apt install \<package name\>'** : (Debian only) installs package;

- **'dpkg -l | grep \<package name\>'** : (Debian only) one way of making sure that package is installed;

- **'hostnamectl set-hostname <name>'** : set the hostname to <name>;

- **'hostnamectl'** : show system hostname and related information;

- **'hostname -I'** : displays IP;

- **'sudo service ssh status'** : checks SSH's status;

- **'ssh -p 4242 \<username\>@\<vm'sip\>'** : connect to VM's terminal via SSH using 42's computer;

- **'pvscan'** : (*physical volumes stand*) lists the physical volumes in LVM group;

- **'vgscan'** : lists volume groups within LVM group;

- **'lvscan'** : lists logical volumes present;

- **'sha1sum \<machinename\>.vdi'** : generate the signature.txt file to be submitted for evaluation.

**DPKG:** *(Debian Package Manager)* dpkg is a tool to install, build, remove and manage Debian packages. The primary and more user-friendly front-end for dpkg is aptitude(1). dpkg itself is controlled entirely via command line parameters, which consist of exactly one action and zero or more options. The action-parameter tells dpkg what to do and options control the behavior of the action in some way.

**APT vs DPKG:** APT is a front-end to dpkg that is more user-friendly than the earlier select front-end. While dpkg handles individual package activities, APT handles package relationships (particularly dependencies), as well as the sourcing and administration of higher-level versioning choices (release tracking and version pinning).

**GREP:** *(global regular expression print)* In the simplest terms, grep (global regular expression print) is a small family of commands that search input files for a search string, and print the lines that match it.

**GETENT:** *(get entry)* getent is a Unix command that helps a user get entries in a number of important text files called databases. This includes the passwd and group databases which store user information – hence getent is a common way to look up user details on Unix. Since getent uses the same name service as the system, getent will show all information, including that gained from network information sources such as LDAP. The databases it searches in are: ahosts, ahostsv4, ahostsv6, aliases, ethers (Ethernet addresses), group, gshadow, hosts, netgroup, networks, passwd, protocols, rpc, services, and shadow.

**CHAGE:** The chage command is self-described as the "change user password expiry information" utility. According to the chage man page: The chage command changes the number of days between password changes and the date of the last password change.

<br>

----
<br>

## Questions I was asked when evaluating the project

<br>

> **What is a Virtual Machine and how does it work?**



>What did you choose as an OS?

        Debian.

> **What are the basic differences between Debian and CentOS / Rocky Linux?**


> **What is the purpose of Virtual Machines?**


> **Because I chose Debian:**

    - What is AppArmor?

    - What is the difference between aptitude and apt?

        
> **Show that UFW is active and running;**
    
        command 'sudo ufw status'

> **Show that SSH Service is active and running;**
   
        command 'sudo service ssh status'

> **Show what OS (Debian, CentOS or whatever) is running;**

        command 'hostnamectl'

> **Show that a user with the evaluatee's login is present, and that it belongs to the "sudo" and "user42" groups;**

        command 'getent group'

> **Create a new user, while making sure that the subject's password rules are in place and being enforced.**

        command 'sudo adduser <newuser>'

> **How did you set up the password rules?**


> **Create a new group called "evaluating";**

        command 'sudo addgroup evaluating'

> **Add the newly created user to the "evaluating" group;**

        command 'sudo adduser <newuser> evaluating'

> **Show that the user has been succesfully added to the group;**

        command 'getent group evaluating'

> **What are the advantages and disadvantages of a strong password policy?**

        A strong password policy makes sure that the system is less prone to be hacked, enhancing security overall. By demanding a minimum length, a combination of digits, special characters and uppercase and lowercase letters, you are making sure that most common attacks are much harder to be effective. This is enhanced by demanding that the password is changed from time to time, and it can be argued that all the mentioned factors before, but perhaps most relevantly this last one, can be useful against social engineering attacks and human errors (such as missplacing a written down password) as well.

> **Check if the hostname of the machine is user42 (evaluatee'slogin42)**;

        command command 'hostnamectl'

> **Change the hostname to the username of the evaluator, reboot the machine, and make sure the change was succesfull. Then, restore it to the original hostname;**

        command 'hostnamectl set-hostname <name>';
        command 'reboot';
        command 'hostnamectl';
        repeat above steps to restore

> **Show the partitions of the virtual machine (the evaluator then compared it to the ones demanded on the bonus part of the subject);**

        command 'lsblk'

> **Give a brief explanation of how LVM works;**


> **Show that SUDO is installed on the VM;**

        command 'sudo -V';

> **Assign the new user to the SUDO group;**

        command 'sudo adduser <newuser> evaluating'

> **Show some basic sudo commands to prove I can use SUDO, and then show that I have implemented the SUDO rules imposed by the subject;**

        (examples)
        command 'sudo -v';
        command 'sudo -k'
        etc etc

> **Check the SUDO log file, and prove that it is being updated everytime a SUDO command takes place;**

  
> **Check that UFW is running and working;**

        command 'sudo ufw status';

> **What is UFW and why should you use it?**

  
> **List UFW's active rules;**

        command 'sudo ufw status';

> **Add a new rule, to open a port. Show that it has been succesfully opened. Finally, delete that rule.**

        command 'sudo ufw allow <port number>';
        command 'sudo ufw status';
        command 'sudo ufw delete allow <port number>';
        command 'sudo ufw status'

> **Check that SSH is running and working;**

        command 'sudo service ssh status';

> **What is SSH and what it is used for?**

 
> **Make sure that SSH service only uses port 4242;**

        command 'cat /etc/ssh/sshd_config';

> **Use SSH using to communicate between your VM and School's 42 computer, and show that you cannot use SSH with root user;**

        command 'hostname -I';
        command 'ssh -p 4242 \<username\>@\<vm'sip\>'

> **By now, the created script was shown a couple of times, and the evaluator had to make sure of that. I was asked to show the script and explain it;**


> **What is cron?**


> **How did you set up this cron job? Change it to run every minute.**


> **Stop the cron job from running without modifying the script. After that, reboot the system and make sure that it worked;**


> **Show that you have set up WordPress;**

        visit the site created by accessing your VM's IP via your 42's computer browser.

> **Show the service you have chosen, and explain how it works and why did you chose it.**

<br>

----
<br>

## Bibliography
<br>

**AppArmor**

https://apparmor.net

**Aptitude | Apt**

https://www.fosslinux.com/43884/apt-vs-aptitude.htm
https://www.linode.com/docs/guides/linux-package-management-overview/

**CentOS**

https://en.wikipedia.org/wiki/CentOS

**Debian / Why Debian?**

https://en.wikipedia.org/wiki/Debian
https://www.debian.org/intro/why_debian
https://www.debian.org/releases/jessie/amd64/ch01s03.html.en
https://en.wikipedia.org/wiki/Debian

**Distro**

https://en.wikipedia.org/wiki/Linux_distribution

**Dynammic VS Static memory storing**

https://byjusexamprep.com/difference-between-static-and-dynamic-memory-allocation-i

**GETENT**

https://en.wikipedia.org/wiki/Getent
https://www.geeksforgeeks.org/getent-command-in-linux-with-examples/

**GUI**

https://en.wikipedia.org/wiki/Graphical_user_interface

**KDUMP**

https://en.wikipedia.org/wiki/Kdump_(Linux)

**Kernel**

https://en.wikipedia.org/wiki/Kernel_(operating_system)

**Linux Kernel**

https://en.wikipedia.org/wiki/Linux_kernel

**LSBLK**

https://linuxhint.com/linux-lsblk-command-tutorial-for-beginners/
https://man7.org/linux/man-pages/man8/lsblk.8.html
https://www.geeksforgeeks.org/lsblk-command-in-linux-with-examples/
https://superuser.com/questions/778686/linux-lsblk-output
					
**LVM**

https://www.techtarget.com/searchdatacenter/definition/logical-volume-management-LVM

**Rocky Linux**

https://en.wikipedia.org/wiki/Rocky_Linux

**SELinux**

https://selinuxproject.org/page/Main_Page

**SSH**

https://www.ucl.ac.uk/isd/what-ssh-and-how-do-i-use-it

**SUDO**

https://phoenixnap.com/kb/linux-sudo-command

**TTY**

https://linuxhint.com/what-does-tty-stand-for/
https://www.geeksforgeeks.org/tty-command-in-linux-with-examples/
https://linuxhint.com/what-does-tty-stand-for/
https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/
https://unix.stackexchange.com/questions/5421/what-is-the-concept-behind-tty-in-linux

**UFW**

https://www.linux.com/training-tutorials/introduction-uncomplicated-firewall-ufw/

**UNIX**

https://en.wikipedia.org/wiki/Unix

**Virtual Machine**

https://cloud.google.com/learn/what-is-a-virtual-machine