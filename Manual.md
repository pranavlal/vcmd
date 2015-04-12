Defines vOICeCmd and explains it's usage
# Introduction #
> vOICeCmd is a utility that allows remote control of the [vOICe](http://www.seeingwithsound.com/winvoice.htm) from the commandline. The vOICe uses windows messages as a remote control mechanism. This approach though easy-to-use cannot be used by the average user primarily because it involves a lot of programming. This utility is a wrapper around that functionality. Now, the entire interface of the vOICe can be accessed using simple to use commandline commands.

# Usage #
all that you need to do to use this interface is to ensure that the vOICe is running. Once that is the case, you can pass one command at a time to the vOICe. For example, to increase the frame rate by four times, you would issue the command:
vOICeCmd Speed\*4
similarly, to mute the vOICe, you would issue the command
vOICeCmd Mute

# Installation #
no special installation is required. Just copy the vOICeCmd executable to the folder where the vOICe executable resides.

# Notes #
1. Only one command at a time can be specified on the commandline using vOICeCmd. This is deliberate. It is easy to implement the passing of multiple commands. However, in my experience, the user needs some time to assimilate any change that takes place in the output of the vOICe. So, as of now, I have decided to stick to the single command approach.

2. It is also important that the vOICe is started manually. I have again decided not to start the vOICe from vOICeCmd. This is because I have no easy way of telling whether the user has enough permissions to run the vOICe.

# Batch file error codes #
If executing vOICeCmd from a batch file, you can use the errorlevel construct to trap the results from vOICeCmd.
0 normal exit,
1 an invalid command was specified,
2 no command was specified on the commandline,
3 the vOICe is not running

# Credits #
this programme would not have been possible without the sample code an easy to follow instructions provided on the seeing with sound website by [Doctor Peter BL Meijer.](http://www.linkedin.com/profile?viewProfile=&key=14302809&authToken=QmUd&authType=NAME_SEARCH&locale=en_US&goback=%2Epsr_*1_peter+meijer_*1_*1_*1_*1_*1_*1_*1_*1_Y_in_110048_*1_*1_*2_*2_*2_Y_Y_*1_Relevance) I would also like to thank members of the [program-l list](http://www.freelists.org/list/program-l) in particular, [Mark Long](http://www.mark-long.co.uk) of [Digital Looking Glass](http://www.digitallookingglass.co.uk/) for helping me with my Visual C++ questions.

# Contacting me #
you can contact me through the seeing with sound mailing list.

# Links of interest #
[The seeing with sound website](http://www.seeingwithsound.com) [Direct link to the page about remote controling the vOICe including a list of commands](http://www.seeingwithsound.com/voicectl.htm)

[My tutorial on the vOICe](http://www.sensorysubstitution.co.uk/tutorial) [Digital Looking Glass](http://www.digitallookingglass.co.uk/)