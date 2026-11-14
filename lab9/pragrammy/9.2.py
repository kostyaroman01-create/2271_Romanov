lst = [ 'Anna', 'Barbara', 'Clara', 'Diana', 'Eva', 'Flora']
def sublist(lst,*d):
    r=[]
    for i in d:
        r.append(lst[i])
    return r

print(sublist(lst,0,2,5))
