import poplib

try:
    M = poplib.POP3('qasid.iitk.ac.in','110')
    user_name=input('Enter Username:')
    password = input('Enter Password:')
    M.user(user_name)
    M.pass_(password)
    
    numMessages,sizo = M.stat()
    print('Number of Emails:',numMessages,'\nMemory Used (Only Inbox) :',sizo/(1024*1024),'MB')
    delRange=int (input("Enter Emails to Be deleted: "))
    print("Deleting ...")
   
    for num in range(delRange):
        M.dele(num+1)
    numMessages,sizo = M.stat()
    print('Number of Emails: ',numMessages ,'\nMemory Used (Only Inbox):', sizo/(1024*1024),'MB')
    M.quit()
except ConnectionError as err:
    print("err"+err)    
